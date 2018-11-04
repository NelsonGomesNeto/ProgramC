import java.util.ArrayList;
import java.util.HashSet;
import javafx.util.Pair;
import java.util.Queue;
ArrayList<Pair<Float, Float>> points, judges;
Integer ptr, p, t, ansPoints; Float lox, hix, loy, hiy, sizeX, sizeY; Boolean loading = true;
Float scl = 0.5;
String[] lines, output;
ArrayList<Float> xa, ya;
ArrayList<ArrayList<Integer>> graph; int[][] matrixGraph; int[] prev; int source = 0, target;

void setup() {
  lines = loadStrings("./in");
  output = loadStrings("./out");
  size(1800, 900);
  fill(0); stroke(0); strokeWeight(2);
  textSize(128); textAlign(CENTER, CENTER);
  ptr = 0; t = 0;
}

void readField() {
  print(str(t) + "\n");
  loading = true;
  lox = 1e11; hix = -lox; loy = lox; hiy = -lox;
  p = int(lines[ptr ++]);
  points = new ArrayList(); graph = new ArrayList(); for (int i = 0; i < 300; i ++) graph.add(new ArrayList());
  for (int i = 0; i < p; i ++, ptr ++) {
    String[] line = lines[ptr].split(" ");
    lox = min(lox, float(line[0])); hix = max(hix, float(line[0]));
    loy = min(loy, float(line[1])); hiy = max(hiy, float(line[1]));
    points.add(new Pair(float(line[0]), float(line[1])));
  }
  points.add(points.get(0));
  sizeX = (height * scl) / abs(hix - lox); sizeY = (height * scl) / abs(hiy - loy);
  print(str(lox) + " " + str(hix) + " " + str(loy) + " " + str(hiy) + "\n");
  print(str(abs(hix - lox)) + " " + str(abs(hiy - loy)) + "\n");
  print(str(sizeX) + " " + sizeY + "\n");
  clear(); background(255);
  findPossibleJudges();
  buildGraph();
  loading = false;
  t ++;
}

void buildGraph() {
  // source (0) -> x (1 : x.size) -> y (1 + x.size() : x.size() + y.size()) -> target (x.size() + y.size() + 1)
  HashSet<Float> x = new HashSet(), y = new HashSet();
  for (int i = 0; i < p; i ++) {
    x.add(points.get(i).getKey());
    y.add(points.get(i).getValue());
  }
  xa = new ArrayList(x); ya = new ArrayList(y);
  target = xa.size() + ya.size() + 1;

  for (float xi: xa) {
    graph.get(0).add(1 + xa.indexOf(xi));
    for (Pair p: judges)
      if (p.getKey().equals(xi))
        graph.get(1 + xa.indexOf(xi)).add(1 + xa.size() + ya.indexOf(p.getValue()));
  }
  for (float yi: ya) graph.get(1 + xa.size() + ya.indexOf(yi)).add(target);
}

Boolean insidePolygon(float x, float y) {
  Boolean c = false;
  for (int i = 0; i < p; i ++) {
    float x1 = points.get(i).getKey(), x2 = points.get(i + 1).getKey();
    float y1 = points.get(i).getValue(), y2 = points.get(i + 1).getValue();
    if (y1 == y2 && y == y1 && x >= min(x1, x2) && x <= max(x1, x2)) return(true);
    if (x1 == x2 && x == x1 && y >= min(y1, y2) && y <= max(y1, y2)) return(true);
    if ((y1 > y) != (y2 > y) && (x < (x2 - x1) * (y - y1) / (y2 - y1) + x1))
      c = !c;
  }
  return(c);
}

void customAdd(Pair<Float, Float> p) {
  if (!points.contains(p)) {
    judges.add(p);
    ansPoints ++;
  }
  else {
    //if (p.getKey().equals(lox)) judges.add(new Pair(lox - abs(hix - lox) * 0.05, p.getValue()));
    //else judges.add(new Pair(hix + abs(hix - lox) * 0.05, p.getValue()));
    //if (p.getValue().equals(loy)) judges.add(new Pair(p.getKey(), loy - abs(hiy - loy) * 0.05));
    //else judges.add(new Pair(p.getKey(), hiy + abs(hiy - loy) * 0.05));
  }
}

float isOnLine(float x, float y) {
  for (int i = 0; i < p; i ++) {
    float x1 = points.get(i).getKey(), x2 = points.get(i + 1).getKey();
    float y1 = points.get(i).getValue(), y2 = points.get(i + 1).getValue();
    if (x1 == x2 && x == x1 && y >= min(y1, y2) && y <= max(y1, y2)) return(1);
    if (y1 == y2 && y == y1 && x >= min(x1, x2) && x <= max(x1, x2)) return(1);
  }
  ansPoints ++;
  return(0);
}

void findPossibleJudges() {
  judges = new ArrayList(); ansPoints = 0;
  HashSet<Float> x = new HashSet(), y = new HashSet();
  float minX = 1e10, maxX = -1e10, minY = 1e10, maxY = -1e10;
  for (int i = 0; i < p; i ++) {
    x.add(points.get(i).getKey());
    y.add(points.get(i).getValue());
  }
  for (float xi: x) { minX = min(minX, xi); maxX = max(maxX, xi); }
  for (float yi: y) { minY = min(minY, yi); maxY = max(maxY, yi); }

  for (float xi: x) {
    if (xi == minX || xi == maxX) continue;
    if (isOnLine(xi, minY) == 0) judges.add(new Pair(xi, minY - abs(maxY - minY) * 0.05 * isOnLine(xi, minY)));
    if (isOnLine(xi, maxY) == 0) judges.add(new Pair(xi, maxY + abs(maxY - minY) * 0.05 * isOnLine(xi, maxY)));
    for (float yi: y) {
      if (yi == minY || yi == maxY || points.contains(new Pair(xi, yi)) || insidePolygon(xi, yi)) continue;
      judges.add(new Pair(xi, yi)); ansPoints ++;
    }
  }
  for (float yi: y) {
    if (yi == minY || yi == maxY) continue;
    if (isOnLine(minX, yi) == 0) judges.add(new Pair(minX - abs(maxX - minX) * 0.05 * isOnLine(minX, yi), yi));
    if (isOnLine(maxX, yi) == 0) judges.add(new Pair(maxX + abs(maxX - minX) * 0.05 * isOnLine(maxX, yi), yi));
  }

  Pair<Float, Float> p1 = new Pair(minX, minY), p2 = new Pair(minX, maxY), p3 = new Pair(maxX, minY), p4 = new Pair(maxX, maxY);
  customAdd(p1); customAdd(p2); customAdd(p3); customAdd(p4);

  text(str(x.size()) + " " + str(y.size()), height - 200, 100);
  text(str(judges.size()), 100, height - 100);
  text("maxFlow = " + maxFlow(), height - 100, height - 100);
}

void drawPoint(Float x, Float y, Integer i, color col, Boolean number) {
  strokeWeight(20);
  stroke(col);
  point(height * scl / 2.0 + (x - lox) * sizeX, height * scl / 2.0 + (y - loy) * sizeY);
  stroke(0);
  strokeWeight(2);
  textSize(64);
  if (number) text(str(i), height * scl / 2.0 + (x - lox) * sizeX, height * scl / 2.0 + (y - loy) * sizeY);
  textSize(128);
}

void draw() {
  if (!loading) {
    // field
    text(output[t - 1], 100, 100);
    for (int i = 0; i < p; i ++) {
      Float x1 = points.get(i).getKey(), x2 = points.get(i + 1).getKey();
      Float y1 = points.get(i).getValue(), y2 = points.get(i + 1).getValue();
      //print(str((x1 - lox) * sizeX) + " " + str((y1 - loy) * sizeY) + " " + str((x2 - lox) * sizeX) + " " + str((y2 - loy) * sizeY) + "\n");
      line(height * scl / 2.0 + (x1 - lox) * sizeX, height * scl / 2.0 + (y1 - loy) * sizeY, height * scl / 2.0 + (x2 - lox) * sizeX, height * scl / 2.0 + (y2 - loy) * sizeY);
    }
    for (int i = 0; i < p; i ++) drawPoint(points.get(i).getKey(), points.get(i).getValue(), i, color(0, 0, 255), false);
    for (int i = 0; i < judges.size(); i ++) drawPoint(judges.get(i).getKey(), judges.get(i).getValue(), i, color(255, 0, 0), false);

    // graph
    stroke(color(128, 0, 128));
    strokeWeight(20);
    float gx = ((width - 10.0) - (height + 10.0)), startX = height + 10.0;
    float gy = height - 100, startY = 50;
    point(startX + 0*gx, height / 2.0);
    for (int i = 1; i <= xa.size(); i ++) {
      point(startX + (1.0/3.0)*gx, startY + (i-0.5)/xa.size()*gy);
      stroke(color(0, 255, 0));
      strokeWeight(5);
      line(startX + 0*gx, height / 2.0, startX + (1.0/3.0)*gx, startY + (i-0.5)/xa.size()*gy);
      stroke(color(128, 0, 128));
      strokeWeight(20);
    }
    for (int i = 1 + xa.size(); i <= xa.size() + ya.size(); i ++) {
      point(startX + (2.0/3.0)*gx, startY + (i-xa.size()-0.5)/ya.size()*gy);
      stroke(color(0, 255, 0));
      strokeWeight(5);
      line(startX + (2.0/3.0)*gx, startY + (i-xa.size()-0.5)/ya.size()*gy, startX + 1*gx, height / 2.0);
      stroke(color(128, 0, 128));
      strokeWeight(20);
    }
    for (int i = 1; i <= xa.size(); i ++)
      for (int j: graph.get(i)) {
        stroke(color(0, 255, 0));
        strokeWeight(5);
        line(startX + (1.0/3.0)*gx, startY + (i-0.5)/xa.size()*gy, startX + (2.0/3.0)*gx, startY + (j-xa.size()-0.5)/ya.size()*gy);
        stroke(color(128, 0, 128));
        strokeWeight(20);
      }
    point(startX + 1*gx, height / 2.0);
    strokeWeight(2);
    stroke(0);
  }
  else { clear(); background(255); }
}

void keyPressed() {
  readField();
}

Boolean bfs() {
  
  Queue<Integer> queue = new Queue(); queue.add(source);
}

int maxFlow() {
  matrixGraph = new int[graph.size()][graph.size()]; path = new int[graph.size()]; prev = new int[graph.size()];
  int mFlow = 0;
  while (bfs()) {
    int flow = int(1e9);
    for (int v = target; v != source; v = prev[v]) flow = min(flow, matrixGraph[prev[v]][v]);
    mFlow += flow;
    for (int v = target; v != source; v = prev[v]) {
      matrixGraph[prev[v]][v] -= flow;
      matrixGraph[v][prev[v]] += flow;
    }
  }
  return(mFlow);
}

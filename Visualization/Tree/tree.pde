import java.util.ArrayList;
import javafx.util.Pair;

String[] lines;
ArrayList<ArrayList<Integer>> tree; int vertices, edges;
ArrayList<Pair<Float, Float>> vertexPosition;

float radious = 50, xSep = 75, ySep = 100, minX = 1e9, maxX = -1e9, depth = -1e9, scale, xScale, yScale;
boolean withPosition = false;
int ptr = 0;

void setup() {
  lines = loadStrings("./in");
  tree = new ArrayList(); vertexPosition = new ArrayList();
  String[] line = lines[0].split(" ");
  vertices = int(line[0]); edges = int(line[1]);
  for (int i = 0; i <= vertices; i ++) {
    tree.add(new ArrayList());
    vertexPosition.add(new Pair(0, 0));
  }
  for (int i = 0; i < edges; i ++) {
    line = lines[i + 1].split(" ");
    tree.get(int(line[0])).add(int(line[1]));
  }
  dfs(1, width / 2.0, 0, -1e9);
  scale = min(height, width) / max(depth, maxX - minX);
  radious = 50 * scale;
  yScale = (height - 2*radious) / depth;
  xScale = (width - 2*radious) / (maxX - minX);

  strokeWeight(2); textSize(32 / str(vertices).length()); textAlign(CENTER, CENTER);
  size(1000, 800);
}

Pair<Float, Float> dfs(int u, float x, float y, float hx) { 
  int size = tree.get(u).size();
  if (size == 0) { // leaf
    while (x <= hx) x += xSep;
    vertexPosition.set(u, new Pair(x, y));
    minX = min(minX, x); maxX = max(maxX, x); depth = max(depth, y);
    return(new Pair(x, x));
  }
  
  float lox = 1e9, hix = -1e9, sonlo = 1e9, sonhi = -1e9; // all vertices below
  for (int i = 0; i < size; i ++) {
    int v = tree.get(u).get(i);
    Pair<Float, Float> lr = dfs(v, x - xSep * (i >= ceil(size / 2.0) ? -1 : 1) * abs(i - ceil(size / 2.0)), y + ySep, maxX);
    lox = min(lox, lr.getKey()); hix = max(hix, lr.getValue());
    sonlo = min(sonlo, vertexPosition.get(v).getKey()); sonhi = max(sonhi, vertexPosition.get(v).getKey());
  }
  vertexPosition.set(u, new Pair((sonlo + sonhi) / 2.0, y));

  minX = min(minX, lox);
  maxX = max(maxX, hix);
  return(new Pair(lox, hix));
}

void draw() {
  // edges
  for (int i = 1; i <= vertices; i ++) {
    float x1 = vertexPosition.get(i).getKey(), y1 = vertexPosition.get(i).getValue();
    for (int j: tree.get(i)) {
      float x2 = vertexPosition.get(j).getKey(), y2 = vertexPosition.get(j).getValue();
      line(radious + (x1 - minX) * xScale, radious + y1 * yScale, radious + (x2 - minX) * xScale, radious + y2 * yScale);
    }
  }
  
  // vertices
  for (int i = 1; i <= vertices; i ++) {
    float x1 = vertexPosition.get(i).getKey(), y1 = vertexPosition.get(i).getValue();
    
    fill(255);
    ellipse(radious + (x1 - minX) * xScale, radious + y1 * yScale, radious, radious);
    fill(0);
    if (withPosition) text(str(i) + " " + str(x1), radious + (x1 - minX) * xScale, radious + y1 * yScale);
    else text(str(i), radious + (x1 - minX) * xScale, radious + y1 * yScale);
  }
}

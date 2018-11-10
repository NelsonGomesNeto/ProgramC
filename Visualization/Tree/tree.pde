import java.util.ArrayList;
import javafx.util.Pair;

String[] lines;
ArrayList<String> vertexLabel;
ArrayList<ArrayList<Integer>> tree; int vertices, edges, biggestLabel = 0;
ArrayList<Pair<Float, Float>> vertexPosition;

float xBorder = 50, yBorder = 50, xRadious = 200, yRadious = 50, xSep = 150, ySep = 100, minX = 1e9, maxX = -1e9, depth = -1e9, scale, xScale, yScale;
boolean withPosition = false;
int ptr = 0;

void setup() {
  lines = loadStrings("./in");
  tree = new ArrayList(); vertexPosition = new ArrayList(); vertexLabel = new ArrayList(); int fp = 0;
  String[] line = lines[fp ++].split(" ");
  vertices = int(line[0]); edges = int(line[1]);
  for (int i = 0; i <= vertices; i ++) {
    tree.add(new ArrayList());
    vertexPosition.add(new Pair(0, 0));
    biggestLabel = max(biggestLabel, lines[fp].length());
    vertexLabel.add(i > 0 ? lines[fp ++] : "");
  }
  for (int i = 0; i < edges; i ++) {
    line = lines[fp ++].split(" ");
    tree.get(int(line[0])).add(int(line[1]));
  }
  dfs(1, width / 2.0, 0, -1e9);
  scale = min(height, width) / max(depth, maxX - minX);
  xRadious = xRadious * scale;
  yScale = (height - 2*yBorder) / depth;
  xScale = (width - 2*xBorder) / (maxX - minX);

  strokeWeight(2); textSize(132 / max(str(vertices).length(), + biggestLabel)); textAlign(CENTER, CENTER);
  size(1200, 800);
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
  ptr = vertices;
  // edges
  for (int i = 1; i <= ptr; i ++) {
    float x1 = vertexPosition.get(i).getKey(), y1 = vertexPosition.get(i).getValue();
    for (int j: tree.get(i)) {
      float x2 = vertexPosition.get(j).getKey(), y2 = vertexPosition.get(j).getValue();
      line(xBorder + (x1 - minX) * xScale, yBorder + y1 * yScale, xBorder + (x2 - minX) * xScale, yBorder + y2 * yScale);
    }
  }
  
  // vertices
  for (int i = 1; i <= ptr; i ++) {
    float x1 = vertexPosition.get(i).getKey(), y1 = vertexPosition.get(i).getValue();
    
    fill(255);
    ellipse(xBorder + (x1 - minX) * xScale, yBorder + y1 * yScale, xRadious, yRadious);
    fill(0);
    if (withPosition) text(str(i) + " " + str(x1), xBorder + (x1 - minX) * xScale, yBorder + y1 * yScale);
    else text(str(i) + "\n" + vertexLabel.get(i), xBorder + (x1 - minX) * xScale, yBorder + y1 * yScale);
 }
}

void keyPressed() {
  if (keyCode == ENTER) ptr = min(ptr + 1, vertices);
}

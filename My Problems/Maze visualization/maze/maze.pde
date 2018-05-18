char maze[][] = new char[1000][1000];
int y, x, yx, myx, mhw, py = 0, px = 0, pn = 0, best = 0, blockSize; float sc = 0.7; int waitTime = 30;
//int[] dx = {0, 1, 0, -1}; int[] dy = {-1, 0, 1, 0};
int[] dx = {0, 0, -1, 1}; int[] dy = {-1, 1, 0, 0};
PFont f;
boolean resetAll = false;

void setup() {
  frameRate(9999);
  f = createFont("Arial", 30, false);
  textFont(f, 30);
  String[] lines = loadStrings("./11.in");
  int[] dim = int(split(lines[0], ' '));
  y = dim[0]; x = dim[1]; yx = max(y, x); myx = min(y, x);
  size(1150, 950);
  for (int i = 0; i < y; i ++)
    for (int j = 0; j < x; j ++)
      maze[i][j] = lines[i + 1].charAt(j);
  mhw = min(height, width);
  blockSize = (mhw / yx);
  println(y, x, height, width);
  //drawMaze();
  thread("startGo");
  //noLoop();
  //go(0, 0);
}

color colorMapping(char c) {
  if (c == 'b') return(color(143, 109, 6));
  if (c == 'p') return(color(173, 171, 173));
  if (c == 'o') return(color(246, 180, 11));
  if (c == 'd') return(color(42, 230, 222));
  return(color(255, 255, 255));
}

float getAngle(char c) {
  if (c == '^') return(-90);
  if (c == '>') return(0);
  if (c == 'v') return(90);
  return(180);
}

void drawCircle(int i, int j, color rgb) {
  fill(rgb);
  ellipse(j * blockSize + blockSize / 1.9, i * (mhw/ yx) + blockSize / 1.9, sc * blockSize, sc * blockSize);
}

void drawArrow(int cy, int cx, int len, float angle, color rgb){
  stroke(rgb);
  strokeWeight(max(9 - 100*min(x, y)/min(height, width), 0.1));
  cx = cx * blockSize + blockSize / 2;
  cy = cy * blockSize + blockSize / 2;
  len = blockSize/4;
  pushMatrix();
  translate(cx, cy);
  rotate(radians(angle));
  line(0,0,-2*len*sc, 0);
  line(len, 0, len - blockSize/4, -blockSize/4);
  line(len, 0, len - blockSize/4, blockSize/4);
  stroke(0, 0, 0);
  strokeWeight(1);
  popMatrix();
}

void drawTreasure(int n) {
  pushMatrix();
  fill(255, 255, 255);
  rect(width - 200, 0, 200, 100);
  fill(0, 0, 200);
  text("best: " + str(best), width - 200, 25);
  text("now: " + str(n), width - 200, 75);
  popMatrix();
}

void draw() {
  //clear();
  //background(255, 255, 255);
  if (resetAll) drawMaze();
  for (int di = py - 1; di < py + 2; di ++) {
    for (int dj = px - 1; dj < px + 2; dj ++) {
      if (di < 0 || dj < 0 || di >= y || dj >= x) continue;
      if (maze[di][dj] != '#') fill(255, 255, 255);
      else fill(0, 0, 0);
      rect(dj * blockSize, di * blockSize, blockSize, blockSize);
      if (maze[di][dj] != '#' && maze[di][dj] != '.' && !invalid(maze[di][dj])) drawCircle(di, dj, colorMapping(maze[di][dj]));
      if (invalid(maze[di][dj]) && maze[di][dj] != '#') drawArrow(di, dj, 16, getAngle(maze[di][dj]), color(179, 40, 250));
    }
  }
  drawCircle(py, px, color(0, 0, 200));
  drawTreasure(pn);
}

void drawMaze() {
  pushMatrix();
  clear();
  background(255, 255, 255);
  for (int di = 0; di < y; di ++) {
    for (int dj = 0; dj < x; dj ++) {
      if (di < 0 || dj < 0 || di >= y || dj >= x) continue;
      if (maze[di][dj] != '#') fill(255, 255, 255);
      else fill(0, 0, 0);
      rect(dj * blockSize, di * blockSize, blockSize, blockSize);
      if (maze[di][dj] != '#' && maze[di][dj] != '.') drawCircle(di, dj, colorMapping(maze[di][dj]));
      if (invalid(maze[di][dj]) && maze[di][dj] != '#') drawArrow(di, dj, 16, getAngle(maze[di][dj]), color(179, 40, 250));
    }
  }
  drawCircle(py, px, color(0, 0, 200));
  popMatrix();
}

void startGo() {
  while (true) {
    best = 0; resetAll = true; delay(1000); resetAll = false;
    go(0, 0, 0);
  }
}

boolean invalid(char c) {
  return(c == '#' || c == '^' || c == '>' || c == 'v' || c == '<');
}

char getDir(int c) {
  if (dx[c] == 0 && dy[c] == -1) return('^');
  if (dx[c] == 1 && dy[c] == 0) return('>');
  if (dx[c] == 0 && dy[c] == 1) return('v');
  if (dx[c] == -1 && dy[c] == 0) return('<');
  return('<');
}

int getScore(char c) {
  if (c == 'b') return(1);
  if (c == 'p') return(5);
  if (c == 'o') return(10);
  if (c == 'd') return(50);
  return(0);
}

int go(int i, int j, int n) {
  best = max(best, n);
  py = i; px = j; pn = n;
  delay(waitTime);
  while (keyPressed) delay(1);
  if (i < 0 || j < 0 || i >= y || j >= x || invalid(maze[i][j]))
    return(0);
  
  char aux = maze[i][j];
  int now = 0;
  for (int k = 0; k < 4; k ++) {
     maze[i][j] = getDir(k);
     now = max(now, go(i + dy[k], j + dx[k], n + getScore(aux)));
     py = i; px = j;
     delay(waitTime);
  }
  maze[i][j] = aux;
  now += getScore(maze[i][j]);
  return(now);
}

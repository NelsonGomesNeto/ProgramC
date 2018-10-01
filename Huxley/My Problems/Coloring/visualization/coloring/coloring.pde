char maze[][] = new char[1000][1000];
int p; int painting[][] = new int[1000][3];
int y, x, yx, myx, mhw, py = -1, px = -1, pk = -1, pn = 0, best = 0, blockSize; float sc = 0.7; int waitTime = 5;
int toPaintY, toPaintX, toPaintColor;
int[] dx = {0, 1, 0, -1}; int[] dy = {-1, 0, 1, 0};
PFont f;
boolean resetAll = false;
int nowSecond, recursionCalls, rec;

void setup() {
  colorMode(HSB, 100, 100, 100);
  frameRate(9999);
  f = createFont("Arial", 30, false);
  textFont(f, 30);
  String[] lines = loadStrings("./../../testCases/9.in");
  int[] dim = int(split(lines[0], ' '));
  y = dim[0]; x = dim[1]; yx = max(y, x); myx = min(y, x);
  size(1150, 950);
  for (int i = 0; i < y; i ++)
    for (int j = 0; j < x; j ++)
      maze[i][j] = lines[i + 1].charAt(j);
  p = int(lines[y + 1]);
  for (int i = 0; i < p; i ++) {
    painting[i] = int(split(lines[y + i + 2], ' '));
    //println(painting[i][0], painting[i][1], painting[i][2]);
  }
  mhw = min(height, width);
  blockSize = (mhw / yx);
  println(y, x, height, width);
  thread("startGo");
}

color colorMapping(char c) {
  if (c >= '0' && c <= '9') return(color((int) (c - '0') * 10, 100, 100));
  return(color(0, 100, 100));
}

boolean invalid(int i, int j) {
  return(i < 0 || j < 0 || i >= y || j >= x || maze[i][j] != '.');
}

char getDir(int dir) {
  if (dir == -1)
  {
    if (invalid(py, px)) return('x');
    else return('o');
  }
  if (dy[dir] == -1 && dx[dir] == 0) return('^');
  if (dy[dir] == 0 && dx[dir] == 1) return('>');
  if (dy[dir] == 1 && dx[dir] == 0) return('v');
  if (dy[dir] == 0 && dx[dir] == -1) return('<');
  return('x');
}

void drawCircle(int i, int j, color rgb) {
  fill(rgb);
  ellipse(j * blockSize + blockSize / 1.9, i * (mhw/ yx) + blockSize / 1.9, sc * blockSize, sc * blockSize);
}

void drawFPS() {
  pushMatrix();
  fill(50, 0, 100);
  rect(width - 200, 0, 200, 300);
  fill(0, 0, 0);
  text("(" + str(toPaintY) + ", " + str(toPaintX) + ")", width - 200, 25);
  text("color: " + str(toPaintColor), width - 200, 75);
  text("fps: " + str(frameRate), width - 200, 125);
  text("rec: " + str(rec), width - 200, 175);
  text("(" + str(py) + ", " + str(px) + ")", width - 200, 225);
  if (pk > -1) text("dir: " + str(getDir(pk)) + " : (" + str(py + dy[max(0, pk)]) + ", " + str(px + dx[max(0, pk)]) + ")", width - 200, 275);
  else text("dir: " + str(getDir(pk)), width - 200, 275);
  popMatrix();
}

void draw() {
  //clear();
  //background(255, 255, 255);
  if (resetAll) drawMaze();
  for (int di = py - 1; di < py + 2; di ++) {
    for (int dj = px - 1; dj < px + 2; dj ++) {
      if (di < 0 || dj < 0 || di >= y || dj >= x) continue;
      if (maze[di][dj] != '#') fill(50, 0, 100);
      else fill(0, 0, 0);
      rect(dj * blockSize, di * blockSize, blockSize, blockSize);
      if (maze[di][dj] != '.' && maze[di][dj] != '#') {//drawCircle(di, dj, colorMapping(maze[di][dj]));
        fill(colorMapping(maze[di][dj]));
        rect(dj * blockSize + (blockSize * (1 - sc) / 2), di * blockSize + (blockSize * (1 - sc) / 2), blockSize * sc, blockSize * sc);
      }
    }
  }
  if (py >= 0 && py < y && px >= 0 && px < x) drawCircle(py, px, color(90, 100, 100));
  drawFPS();
}

void drawMaze() {
  pushMatrix();
  clear();
  background(50, 0, 100);
  for (int di = 0; di < y; di ++) {
    for (int dj = 0; dj < x; dj ++) {
      if (maze[di][dj] != '#') fill(50, 0, 100);
      else fill(0, 0, 0);
      rect(dj * blockSize, di * blockSize, blockSize, blockSize);
    }
  }
  popMatrix();
}

void startGo() {
  while (true) {
    best = 0; resetAll = true; delay(1000); resetAll = false;
    nowSecond = second();
    recursionCalls = 0;
    for (int i = 0; i < p; i ++) {
      toPaintY = painting[i][0]; toPaintX = painting[i][1]; toPaintColor = painting[i][2]; 
      go(painting[i][0], painting[i][1], (char) (painting[i][2] + '0')); delay(waitTime);
    }
  }
}

int go(int i, int j, char col) {
  recursionCalls ++;
  if (nowSecond != second()) {
    nowSecond = second();
    rec = recursionCalls; recursionCalls = 0;
  }
  py = i; px = j; pk = -1;
  delay(waitTime);
  if (i < 0 || j < 0 || i >= y || j >= x || maze[i][j] == '#' || maze[i][j] == col)
    return(0);
  
  maze[i][j] = col;
  for (int k = 0; k < 4; k ++) {
     pk = k;
     while (keyPressed) delay(50);
     go(i + dy[k], j + dx[k], col);
     while (keyPressed) delay(50);
     recursionCalls ++;
     py = i; px = j;
     delay(waitTime);
  }
  return(0);
}

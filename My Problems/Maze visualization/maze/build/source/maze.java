import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class maze extends PApplet {

char maze[][] = new char[1000][1000];
int y, x, yx, myx, mhw, py = 0, px = 0, pn = 0, best = 0, blockSize; float sc = 0.7f; int waitTime = 30;
//int[] dx = {0, 1, 0, -1}; int[] dy = {-1, 0, 1, 0};
int[] dx = {0, 1, 0, -1}; int[] dy = {-1, 0, 1, 0};
PFont f;
boolean resetAll = false;
int nowSecond, recursionCalls, rec;

public void setup() {
  frameRate(9999);
  f = createFont("Arial", 30, false);
  textFont(f, 30);
  String[] lines = loadStrings("./in");
  int[] dim = PApplet.parseInt(split(lines[0], ' '));
  y = dim[0]; x = dim[1]; yx = max(y, x); myx = min(y, x);
  
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

public int colorMapping(char c) {
  if (c == 'b') return(color(143, 109, 6));
  if (c == 'p') return(color(173, 171, 173));
  if (c == 'o') return(color(246, 180, 11));
  if (c == 'd') return(color(42, 230, 222));
  return(color(255, 255, 255));
}

public float getAngle(char c) {
  if (c == '^') return(-90);
  if (c == '>') return(0);
  if (c == 'v') return(90);
  return(180);
}

public void drawCircle(int i, int j, int rgb) {
  fill(rgb);
  ellipse(j * blockSize + blockSize / 1.9f, i * (mhw/ yx) + blockSize / 1.9f, sc * blockSize, sc * blockSize);
}

public void drawArrow(int cy, int cx, int len, float angle, int rgb){
  stroke(rgb);
  strokeWeight(max(9 - 100*min(x, y)/min(height, width), 0.1f));
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

public void drawTreasure(int n) {
  pushMatrix();
  fill(255, 255, 255);
  rect(width - 200, 0, 200, 200);
  fill(0, 0, 200);
  text("best: " + str(best), width - 200, 25);
  text("now: " + str(n), width - 200, 75);
  text("fps: " + str(frameRate), width - 200, 125);
  text("rec: " + str(rec), width - 200, 175);
  popMatrix();
}

public void draw() {
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

public void drawMaze() {
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

public void startGo() {
  while (true) {
    best = 0; resetAll = true; delay(1000); resetAll = false;
    nowSecond = second();
    recursionCalls = 0;
    go(0, 0, 0);
  }
}

public boolean invalid(char c) {
  return(c == '#' || c == '^' || c == '>' || c == 'v' || c == '<');
}

public char getDir(int c) {
  if (dx[c] == 0 && dy[c] == -1) return('^');
  if (dx[c] == 1 && dy[c] == 0) return('>');
  if (dx[c] == 0 && dy[c] == 1) return('v');
  if (dx[c] == -1 && dy[c] == 0) return('<');
  return('<');
}

public int getScore(char c) {
  if (c == 'b') return(1);
  if (c == 'p') return(5);
  if (c == 'o') return(10);
  if (c == 'd') return(50);
  return(0);
}

public int go(int i, int j, int n) {
  recursionCalls ++;
  if (nowSecond != second()) {
    nowSecond = second();
    rec = recursionCalls; recursionCalls = 0;
  }
  best = max(best, n);
  py = i; px = j; pn = n;
  delay(waitTime);
  while (!keyPressed) delay(1);
  if (i < 0 || j < 0 || i >= y || j >= x || invalid(maze[i][j]))
    return(0);

  char aux = maze[i][j];
  int now = 0;
  for (int k = 0; k < 4; k ++) {
     maze[i][j] = getDir(k);
     now = max(now, go(i + dy[k], j + dx[k], n + getScore(aux)));
     recursionCalls ++;
     py = i; px = j;
     delay(waitTime);
  }
  //maze[i][j] = aux;
  now += getScore(maze[i][j]);
  return(now);
}
  public void settings() {  size(1150, 950); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "maze" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

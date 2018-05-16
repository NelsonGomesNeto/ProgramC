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
int y, x, yx, py = 0, px = 0; float sc = 0.7f;
boolean kp = false;

public void setup() {
  
  frameRate(60);
  String[] lines = loadStrings("1.in");
  int[] dim = PApplet.parseInt(split(lines[0], ' '));
  y = dim[0]; x = dim[1]; yx = max(y, x);
  for (int i = 0; i < y; i ++)
    for (int j = 0; j < x; j ++)
      maze[i][j] = lines[i + 1].charAt(j);
  println(y, x, height, width);
  go(0, 0);
}

public int colorMapping(char c) {
  if (c == 'b') return(color(143, 109, 6));
  if (c == 'p') return(color(173, 171, 173));
  if (c == 'o') return(color(246, 180, 11));
  if (c == 'd') return(color(42, 230, 222));
  return(color(255, 255, 255));
}

public void drawCircle(int i, int j, int rgb) {
  fill(rgb);
  ellipse(j * (width / yx) + (width / yx) / 2, i * (height/ yx) + (height / yx) / 2, sc * (width / yx), sc * (height / yx));
}

public void mazeDraw() {
  for (int di = 0; di < y; di ++) {
    for (int dj = 0; dj < x; dj ++) {
      if (maze[di][dj] != '#') fill(255, 255, 255);
      else fill(0, 0, 0);
      rect(dj * (width / yx), di * (height / yx), (width / yx), (height / yx));
      if (maze[di][dj] != '#' && maze[di][dj] != '.') drawCircle(di, dj, colorMapping(maze[di][dj]));
    }
  }
  drawCircle(py, px, color(0, 0, 200));
}

public void keyPressed() {
  if (keyPressed == true)
    kp = true;
  kp = false;
}

public void go(int i, int j) {
  mazeDraw();
  println(i, j);
  if (i >= y) return;
  while (!kp) println(kp);
  py ++;
  go(i + 1, j);
}
  public void settings() {  size(400, 400); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "maze" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

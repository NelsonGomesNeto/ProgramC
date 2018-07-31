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

public class Bitmap extends PApplet {

int bitmap[][] = new int[1024][1024];
int y, x, blockSize;

public void setup() {
  
  colorMode(HSB, 360, 100, 100);

  String[] lines = loadStrings("./in");
  int[] yx = PApplet.parseInt(split(lines[0], ' '));
  y = yx[0]; x = yx[1];
  print(y, x, "\n");
  for (int i = 0; i < y; i ++) {
    char[] line = lines[i + 1].toCharArray();
    for (int j = 0; j < x; j ++) {
      bitmap[i][j] = line[j] - '0';
      print(bitmap[i][j]);
    } print("\n");
  }

  blockSize = min(height, width) / max(y, x);
}

public void drawBlock(int i, int j) {
  fill(0, bitmap[i][j] * 100, (1 - bitmap[i][j]) * 100);
  rect(j * blockSize, i * blockSize, blockSize, blockSize);
}

public void draw() {
  for (int i = 0; i < y; i ++)
    for (int j = 0; j < x; j ++)
      drawBlock(i, j);
}
  public void settings() {  size(900, 900); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "Bitmap" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

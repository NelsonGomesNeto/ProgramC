char maze[][] = new char[1000][1000];
int y, x, yx, py = 0, px = 0; float sc = 0.7; int waitTime = 50;
boolean kp = false;
int[] dx = {0, 1, 0, -1}; int[] dy = {-1, 0, 1, 0};

void setup() {
  frameRate(144);
  String[] lines = loadStrings("./../realMaze/1.in");
  int[] dim = int(split(lines[0], ' '));
  y = dim[0]; x = dim[1]; yx = max(y, x);
  size(1000, 1000);
  for (int i = 0; i < y; i ++)
    for (int j = 0; j < x; j ++)
      maze[i][j] = lines[i + 1].charAt(j);
  println(y, x, height, width);
  thread("startGo");
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
  ellipse(j * (width / yx) + (width / yx) / 1, i * (height/ yx) + (height / yx) / 1, sc * (width / yx), sc * (height / yx));
}

void drawArrow(int cy, int cx, int len, float angle, color rgb){
  stroke(rgb);
  strokeWeight(max(9 - min(x*100, y*100)/min(height, width), 0.1));
  cx = cx * (width / yx) + (width / yx) / 2;
  cy = cy * (height / yx) + (height / yx) / 2;
  len = (min(width, height) / yx) / 4;
  pushMatrix();
  translate(cx, cy);
  rotate(radians(angle));
  line(0,0,len, 0);
  line(len, 0, len - 8, -8);
  line(len, 0, len - 8, 8);
  stroke(0, 0, 0);
  strokeWeight(1);
  popMatrix();
}

void draw() {
  clear();
  background(255, 255, 255);
  for (int di = 0; di < y; di ++) {
    for (int dj = 0; dj < x; dj ++) {
      if (maze[di][dj] != '#') fill(255, 255, 255);
      else fill(0, 0, 0);
      rect(dj * (width / yx), di * (height / yx), (width / yx), (height / yx));
      if (maze[di][dj] != '#' && maze[di][dj] != '.') drawCircle(di, dj, colorMapping(maze[di][dj]));
      if (invalid(maze[di][dj]) && maze[di][dj] != '#') drawArrow(di, dj, 16, getAngle(maze[di][dj]), color(179, 40, 250));
    }
  }
  drawCircle(py, px, color(0, 0, 200));
}

void startGo() {
  while (true) {
    go(0, 0);
  }
}

boolean invalid(char c) {
  return(c == '#' || c == '^' || c == '>' || c == 'v' || c == '<');
}

char getDir(int c) {
  if (c == 0) return('^');
  if (c == 1) return('>');
  if (c == 2) return('v');
  return('<');
}

int go(int i, int j) {
  py = i; px = j;
  println(i, j, keyPressed);
  while (keyPressed) delay(1);
  delay(waitTime);
  if (i < 0 || j < 0 || i >= y || j >= x || invalid(maze[i][j]))
    return(0);
  
  char aux = maze[i][j];
  for (int k = 0; k < 4; k ++) {
     maze[i][j] = getDir(k);
     go(i + dy[k], j + dx[k]);
  }
  maze[i][j] = aux;
  return(0);
}

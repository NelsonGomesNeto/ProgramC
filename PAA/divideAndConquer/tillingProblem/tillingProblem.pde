int table[][] = new int[1024][1024];
int now = 0;
int size, y, x, biggest, waitTime = 10, nowli, nowlj, nowhi, nowhj; float blockSize;
int[] dci = {0, 0, 1, 1}, dcj = {1, 0, 0, 1};
int[] done = new int[361];
PGraphics pg;

void setup() {
  String[] lines = loadStrings("./in");
  size = int(lines[0]);
  biggest = (size*size - 1) / 3;
  int[] pos = int(split(lines[1], ' '));
  y = pos[0]; x = pos[1];
  table[y][x] = -1;
  size(900, 900);
  blockSize = float(min(height, width)) / size;
  print(blockSize);
  colorMode(HSB, 360, 100, 100);

  pg = createGraphics(900, 900);
  pgDrawBlock(y, x);
  thread("startSolve");
}

void pgDrawBlock(int i, int j) {
  pg.beginDraw();
  pg.colorMode(HSB, 360, 100, 100);
  if (table[i][j] == -1) pg.fill(0, 0, 0);
  else pg.fill(360*(float(table[i][j]) / biggest), 100, 100);
  pg.rect(i * blockSize, j * blockSize, blockSize, blockSize);
  pg.endDraw();
}

void drawBlock(int i, int j) {
  if (table[i][j] == -1) fill(0, 0, 0);
  else fill(360*(float(table[i][j]) / biggest), 100, 100);
  rect(i * blockSize, j * blockSize, blockSize, blockSize);
}

void draw() {
  // for (int i = nowli; i < nowhi; i ++)
  //   for (int j = nowlj; j < nowhj; j ++)
  //     drawBlock(i, j);
  image(pg, 0, 0);
}

void startSolve() {
  now = 0; for (int i = 0; i <= 360; i ++) done[i] = 0;
  solve(0, 0, size - 1, size - 1, y, x);
}

int getDir(int mi, int mj, int y, int x) {
  if (mj < x && mi >= y) return(0);
  if (mj >= x && mi >= y) return(1);
  if (mj >= x && mi <= y) return(2);
  if (mj <= x && mi <= y) return(3);
  return(3);
}

void putColor(int mi, int mj, int dir, int col) {
  for (int i = 0; i < 2; i ++)
    for (int j = 0; j < 2; j ++) {
      if (dci[dir] == i && dcj[dir] == j) continue;
      table[mi + i][mj + j] = col;
      pgDrawBlock(mi + i, mj + j);
    }
  // nowli = mi; nowlj = mj; nowhi = mi + 2; nowhj = mj + 2;
}

void solve(int li, int lj, int hi, int hj, int y, int x) {
  if (li >= hi && lj >= hj) return;
  now ++;
  int mi = (li + hi) / 2, mj = (lj + hj) / 2;
  int dir = getDir(mi, mj, y, x);

  // int newColor; do newColor = int(random(0, 360)); while (done[newColor] == 1);
  // done[newColor] = 1;
  putColor(mi, mj, dir, now);

  delay(waitTime);
  if (dir == 0) solve(li, mj + 1, mi, hj, y, x);
  else solve(li, mj + 1, mi, hj, mi, mj + 1);
  if (dir == 1) solve(li, lj, mi, mj, y, x);
  else solve(li, lj, mi, mj, mi, mj);
  if (dir == 2) solve(mi + 1, lj, hi, mj, y, x);
  else solve(mi + 1, lj, hi, mj, mi + 1, mj);
  if (dir == 3) solve(mi + 1, mj + 1, hi, hj, y, x);
  else solve(mi + 1, mj + 1, hi, hj, mi + 1, mj + 1);
}

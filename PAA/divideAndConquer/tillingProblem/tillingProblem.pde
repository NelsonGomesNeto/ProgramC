import java.util.Queue;
import java.util.ArrayDeque;

int table[][] = new int[1024][1024];
int now = 0;
int size, y, x, biggest, waitTime = 1000, nowli, nowlj, nowhi, nowhj; float blockSize;
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
  print(blockSize, "\n");
  colorMode(HSB, 360, 100, 100);

  pg = createGraphics(900, 900);
  pg.beginDraw();
  pgDrawBlock(y, x);
  pg.endDraw();
  thread("startSolve");
}

void pgDrawBlock(int i, int j) {
  pg.colorMode(HSB, 360, 100, 100);
  if (table[i][j] == -1) pg.fill(0, 0, 0);
  else pg.fill(300*(float(table[i][j]) / (log(biggest)/log(4))), 100, 100);
  pg.rect(j * blockSize, i * blockSize, blockSize, blockSize);
}

void drawBlock(int i, int j) {
  if (table[i][j] == -1) fill(0, 0, 0);
  else fill(360*(float(table[i][j]) / biggest), 100, 100);
  rect(j * blockSize, i * blockSize, blockSize, blockSize);
}

void draw() {
  // for (int i = nowli; i < nowhi; i ++)
  //   for (int j = nowlj; j < nowhj; j ++)
  //     drawBlock(i, j);
  image(pg, 0, 0);
}

int getDir(int mi, int mj, int y, int x) {
  if (mj < x && mi >= y) return(0);
  if (mj >= x && mi >= y) return(1);
  if (mj >= x && mi <= y) return(2);
  if (mj <= x && mi <= y) return(3);
  return(3);
}

void putColor(int mi, int mj, int dir, int col) {
  // pg.beginDraw();
  for (int i = 0; i < 2; i ++)
    for (int j = 0; j < 2; j ++) {
      if (dci[dir] == i && dcj[dir] == j) continue;
      table[mi + i][mj + j] = col;
      pgDrawBlock(mi + i, mj + j);
    }
  // pg.endDraw();
  // nowli = mi; nowlj = mj; nowhi = mi + 2; nowhj = mj + 2;
}

void startSolve() {
  now = 0; for (int i = 0; i <= 360; i ++) done[i] = 0;
  solveDFS(0, 0, size - 1, size - 1, y, x, 0);
  //solveBFS();
}

void solveDFS(int li, int lj, int hi, int hj, int y, int x, int c) {
  if (li >= hi && lj >= hj) return;
  int mi = (li + hi) / 2, mj = (lj + hj) / 2;
  int dir = getDir(mi, mj, y, x);

  // int newColor; do newColor = int(random(0, 360)); while (done[newColor] == 1);
  // done[newColor] = 1;
  pg.beginDraw();
  putColor(mi, mj, dir, c);
  pg.endDraw();

  delay(waitTime);
  now ++;
  if (dir == 0) solveDFS(li, mj + 1, mi, hj, y, x, c + 1);
  else solveDFS(li, mj + 1, mi, hj, mi, mj + 1, c + 1);
  if (dir == 1) solveDFS(li, lj, mi, mj, y, x, c + 1);
  else solveDFS(li, lj, mi, mj, mi, mj, c + 1);
  if (dir == 2) solveDFS(mi + 1, lj, hi, mj, y, x, c + 1);
  else solveDFS(mi + 1, lj, hi, mj, mi + 1, mj, c + 1);
  if (dir == 3) solveDFS(mi + 1, mj + 1, hi, hj, y, x, c + 1);
  else solveDFS(mi + 1, mj + 1, hi, hj, mi + 1, mj + 1, c + 1);
}

void solveBFS() {
  Queue<int[]> queue = new ArrayDeque();
  int[] aux = {0, 0, size - 1, size - 1, y, x, 0};
  queue.add(aux.clone());
  int level = -1; pg.beginDraw();
  while (queue.size() > 0) {
    int li, lj, hi, hj, yy, xx, c;
    li = queue.peek()[0]; lj = queue.peek()[1]; hi = queue.peek()[2]; hj = queue.peek()[3]; yy = queue.peek()[4]; xx = queue.peek()[5]; c = queue.peek()[6]; queue.remove();
    if (li >= hi && lj >= hj) continue;
    if (c > level)
    {
      pg.endDraw();
      delay(waitTime);
      level = c;
      pg.beginDraw();
    }

    int mi = (li + hi) / 2, mj = (lj + hj) / 2;
    int dir = getDir(mi, mj, yy, xx);

    putColor(mi, mj, dir, c);

    if (dir == 0) aux = new int[] {li, mj + 1, mi, hj, yy, xx, c + 1};
    else aux = new int[] {li, mj + 1, mi, hj, mi, mj + 1, c + 1};
    queue.add(aux.clone());
    if (dir == 1) aux = new int[] {li, lj, mi, mj, yy, xx, c + 1};
    else aux = new int[] {li, lj, mi, mj, mi, mj, c + 1};
    queue.add(aux.clone());
    if (dir == 2) aux = new int[] {mi + 1, lj, hi, mj, yy, xx, c + 1};
    else aux = new int[] {mi + 1, lj, hi, mj, mi + 1, mj, c + 1};
    queue.add(aux.clone());
    if (dir == 3) aux = new int[] {mi + 1, mj + 1, hi, hj, yy, xx, c + 1};
    else aux = new int[] {mi + 1, mj + 1, hi, hj, mi + 1, mj + 1, c + 1};
    queue.add(aux.clone());
  }
  pg.endDraw();
}

int bitmap[][] = new int[1024][1024];
int y, x, blockSize;

void setup() {
  size(900, 900);
  colorMode(HSB, 360, 100, 100);

  String[] lines = loadStrings("./in");
  int[] yx = int(split(lines[0], ' '));
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

void drawBlock(int i, int j) {
  fill(0, bitmap[i][j] * 100, (1 - bitmap[i][j]) * 100);
  rect(j * blockSize, i * blockSize, blockSize, blockSize);
}

void draw() {
  for (int i = 0; i < y; i ++)
    for (int j = 0; j < x; j ++)
      drawBlock(i, j);
}
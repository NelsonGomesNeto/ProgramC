String[] lines;
int[][] puzzle;
int n, m;
float blockSize, pieceScale = 0.8;

void setup() {
  lines = loadStrings("./in");
  String[] line = lines[0].split(" ");
  n = int(line[0]); m = int(line[1]);
  puzzle = new int[n][m];
  for (int i = 0; i < n; i ++) {
    line = lines[i + 1].replaceAll("  ", " ").split(" ");
    for (int j = 0; j < m; j ++) {
      puzzle[i][j] = int(line[j]);
      if (puzzle[i][j] == -1) puzzle[i][j] = 15;
    }
  }

  size(900, 900);
  textAlign(CENTER, CENTER);
  blockSize = (min(height, width) - 200) / max(n, m);
}

// line (1 (horizontal) : 2 (vertical)) flow 2
// corner (3 (left, down), 4 (right, down), 5 (right, up), 6 (left, up)) flow 2
// square (7 (left), 8 (down), 9 (right), 10 (up)) flow 2
// dot (11 (left), 12 (down), 13 (right), 14 (up)) flow 1
void drawPiece(int i, int j) {
  if (puzzle[i][j] < 3 && puzzle[i][j] == 2) rotate(radians(90));
  else if (puzzle[i][j] >= 3) rotate(radians(-90 * ((puzzle[i][j] - 3) % 4)));
  
  if (puzzle[i][j] < 3) { // line
    line(0, 0, blockSize * pieceScale / 2, 0);
    line(0, 0, -blockSize * pieceScale / 2, 0);
  }
  else if (puzzle[i][j] < 7) { // corner
    line(0, 0, -blockSize * pieceScale / 2, 0);
    line(0, 0, 0, blockSize * pieceScale / 2);
  }
  else if (puzzle[i][j] < 15) {
    ellipse(0, 0, blockSize * pieceScale / 6, blockSize * pieceScale / 6);
    line(0, 0, -blockSize * pieceScale / 2, 0);
  }

  if (puzzle[i][j] < 3 && puzzle[i][j] == 2) rotate(radians(360 - 90));
  else if (puzzle[i][j] >= 3) rotate(radians(90 * ((puzzle[i][j] - 3) % 4)));
}

void draw() {
  translate(100, 100);
  for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++) {
      translate(j * blockSize, i * blockSize);
      rect(0, 0, blockSize, blockSize);
      fill(0); text(str(puzzle[i][j]), 20, 20); fill(255);
      translate(0.5 * blockSize, 0.5 * blockSize);
      drawPiece(i, j);
      translate(-(j + 0.5) * blockSize, -(i + 0.5) * blockSize);
    }
}

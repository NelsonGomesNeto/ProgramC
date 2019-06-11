#include <ctype.h>
#define TOP 0, 0, 0, 1
#define TOPBT 0, 1, 0, 0
#define BOT 1, 0, 1, 1
#define BOTBT 1, 1, 1, 0
#define LEFT 0, 0, 1, 0
#define LEFTBT 1, 0, 0, 0
#define RIGHT 0, 1, 1, 1
#define RIGHTBT 1, 1, 0, 1

char cube[6][2][2 + 1], color[6 + 1] = {'B', 'G', 'W', 'Y', 'R', 'O', '\0'}, face[6 + 1] = {'U', 'D', 'F', 'B', 'R', 'L', '\0'};
int mapping[6][4][5] = {{{2, TOP}, {5, TOP}, {3, TOP}, {4, TOP}}, // Top
                        {{5, BOT}, {2, BOT}, {4, BOT}, {3, BOT}}, // Down
                        {{0, BOTBT}, {4, LEFTBT}, {1, TOP}, {5, RIGHT}}, // Front
                        {{4, RIGHTBT}, {0, TOPBT}, {5, LEFT}, {1, BOT}}, // Back
                        {{2, RIGHT}, {0, RIGHT}, {3, LEFTBT}, {1, RIGHT}}, // Right
                        {{0, LEFT}, {2, LEFT}, {1, LEFT}, {3, RIGHTBT}} // Left
                       };

void printMapping()
{
  int i, j;
  for (i = 0; i < 6; i ++)
  {
    printf("Color: %c, maps:", color[i]);
    for (j = 0; j < 4; j ++)
      printf(" %c%c", color[mapping[i][j][0]], j < 3 ? ',' : '\n');
  }
  printf("\n");
}

// Resolve o cubo
void resetCube()
{
  int i, j, k;
  for (i = 0; i < 6; i ++)
    for (j = 0; j < 2; j ++)
      for (k = 0; k < 2; k ++)
        cube[i][j][k] = color[i];
}

// Imprime o cube
void printCube()
{
  int i, j, k;
  for (i = 0; i < 6; i ++)
  {
    printf("%c -> ", face[i]);
    for (j = 0; j < 2; j ++)
    {
      if (j > 0) printf("     ");
      for (k = 0; k < 2; k ++)
        printf("%c", cube[i][j][k]);
      printf("\n");
    }
    printf("\n");
  }
}

void turn(int face)
{
  printf("Turning face: %c\n", color[face]);
  int i, j;
  char aux[2][5];
  for (i = 0; i < 2; i ++)
    for (j = 0; j < 2; j ++)
      aux[i][j] = cube[face][i][j];

  cube[face][0][0] = aux[1][0];
  cube[face][0][1] = aux[0][0];
  cube[face][1][0] = aux[1][1];
  cube[face][1][1] = aux[0][1];

  for (i = 0; i < 4; i ++)
  {
    aux[0][i] = cube[mapping[face][i][0]][mapping[face][i][1]][mapping[face][i][2]];
    aux[1][i] = cube[mapping[face][i][0]][mapping[face][i][3]][mapping[face][i][4]];
  }

  for (i = 0; i < 4; i ++)
  {
    cube[mapping[face][i][0]][mapping[face][i][1]][mapping[face][i][2]] = aux[0][(i + 3) % 4];
    cube[mapping[face][i][0]][mapping[face][i][3]][mapping[face][i][4]] = aux[1][(i + 3) % 4];
  }

}

int getFaceFromChar(char com)
{
  if (com == 'R') return(4);
  if (com == 'U') return(0);
  if (com == 'F') return(2);
  if (com == 'L') return(5);
  if (com == 'D') return(1);
  if (com == 'B') return(3);
}

void execCommand(char command[])
{
  int i;
  for (i = 0; command[i]; i ++)
    turn(getFaceFromChar(toupper(command[i])));
}
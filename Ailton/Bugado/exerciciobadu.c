#include <stdio.h>



#define LIN 5

#define COL 4

int main()

{

	float notas[LIN][COL];



	// preencher a primeira linha

	notas[0][0] = 5.5;

	notas[0][1] = 6.0;

	notas[0][2] = 4.0;

	notas[0][3] = 2.0;



	// segunda linha

	notas[1][0] = 7.3;

	notas[1][1] = 4.0;

	notas[1][2] = 5.0;

	notas[1][3] = 8.0;



	// terceira linha

	notas[2][0] = 9.1;

	notas[2][1] = 9.0;

	notas[2][2] = 8.5;

	notas[2][3] = 10.0;



	// quarta linha

	notas[3][0] = 3.2;

	notas[3][1] = 10.0;

	notas[3][2] = 10.0;

	notas[3][3] = 9.5;



	// quinta linha

	notas[4][0] = 9.1;

	notas[4][1] = 8.0;

	notas[4][2] = 7.5;

	notas[4][3] = 10.0;

	int printarX, printarY;
	for (printarY = 0; printarY < LIN; printarY ++)
	{
		for (printarX = 0; printarX < COL; printarX ++)
		{
			printf("%f ", notas[printarY][printarX]);
		}
		printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~\n");
	for (printarY = 0; printarY < COL; printarY ++)
	{
		for (printarX = 0; printarX < LIN; printarX ++)
		{
			printf("%f ", notas[printarX][printarY]);
		}
		printf("\n");
	}
	printf("~~~~~~~~~~~~~~~~\n");
	for (printarY = LIN - 1; printarY >= 0; printarY --)
	{
		for (printarX = COL - 1; printarX >= 0; printarX --)
		{
			printf("%f ", notas[printarY][printarX]);
		}
		printf("\n");
	}
	return 0;

}

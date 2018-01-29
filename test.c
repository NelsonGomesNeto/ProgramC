#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float n1, n2, n3, a, b;
    int c;

    scanf("%f %f %f", &n1, &n2, &n3);

    a = n1 + n2 + n3;
    b = a / 3.0;
    c = 0;
    printf("%f\n", b);

    if (n1 >= b){
        ++c;
    }
    if (n2 >= b){
        ++c;
    }
    if (n3 >= b){
        ++c;
    }


    printf("%d", c);
	return 0;
}
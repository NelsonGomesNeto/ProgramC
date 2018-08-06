#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int produto(int n, int k, int a) {
    if(a == n) {
        return 0;
    }
    else {
        return k + produto(n, k, a + 1);
    }
}

void multiplas_entradas() {
    int n, k;
    if(scanf("%d %d", &n, &k) == EOF) {
        return;
    }
    else {
        printf("%d\n", produto(n, k, 0));
        multiplas_entradas();
    }
}


int main() {
    multiplas_entradas();

	return 0;
}
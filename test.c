#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void printar_permutacao(char x[], int aux, int cont, int aux2) {
    if(aux == cont) {
        printf("\n");
    }
    else if(aux == 0) {
        printf("Caso %d: %c", aux2, x[aux]);
        printar_permutacao(x, aux + 1, cont, aux2);
    }
    else {
        printf("%c", x[aux]);
        printar_permutacao(x, aux + 1, cont, aux2);
    }
}


void maior(char x[], int aux, int aux2, int cont, int aux3) {
    if(aux == cont) {
        return;
    }
    else if(aux2 == cont) {
        maior(x, aux + 1, aux + 2, cont, aux3);
    }
    else if(x[aux] <= x[aux2]) {
        aux3 = x[aux];
        x[aux] = x[aux2];
        x[aux2] = aux3;
        maior(x, aux, aux2 + 1, cont, aux3);
    }
    else {
        maior(x, aux, aux2 + 1, cont, aux3);
    }
}

int ler_string(char x[], int aux) {
    scanf("%c", &x[aux]);
    printf("<%c>\n", x[aux]); // Preste atenção na saída
    if(x[aux] == '\n') {
        return 0;
    }
    else {
        return 1 + ler_string(x, aux + 1);
    }
}

void permutacao(int n, int aux, char x[]) {
    if(aux == n) {
        return;
    }
    else {
        int resultado = ler_string(x, 0);
        maior(x, 0, 0, resultado, 0);
        printar_permutacao(x, 0, resultado, aux);
        permutacao(n, aux + 1, x);
    }
}

int main() {
    int n;
    char string[100000];
    scanf("%d", &n); // Depois teste com: scanf("%d\n", &n);
    permutacao(n, 0, string);

	return 0;
}
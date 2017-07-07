#include <stdio.h>
#include <malloc.h>

int cubo(int val) {
    return val*val*val;
}
int* map(int* src, int tam, int f(int)) {
    int i;
    int* to = malloc(sizeof(int) * tam);
    for (i = 0; i < tam; i++)
        to[i] = f(src[i]);
     return to;
}

int main() {
    int i, arr[3] = {0,1,2};
    int* res = map(arr, 3, cubo);
    for (i = 0; i < 3; i++)
        printf("%d\n", res[i]);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct data data_t;

struct data {
    int plays, distance;
    char guard[1000];
};

void goThrough(data_t test, int i, int *j, char faces, int count) {
    if (faces == '7')
        return;
    else {
        test.guard[i] = faces;
        count += loop(test, i + 1, j);
    }
    goThrough(test, i, j, faces + 1, count);
}

int sum(data_t test, int i, int sumDice) {
    if (i == test.plays)
        return sumDice;
    else
        sumDice += (test.guard[i] - '0');
    sum(test, i + 1, sumDice);
}

int loop(data_t test, int i, int *j) {
    if (i == test.plays) {
        test.guard[i] = '\0';
        int n = sum(test, 0, 0);
        printf("%s = %d\n", test.guard, n);
        return (n >= test.distance) ? *j += 1 : *j; 
    }
    else
        goThrough(test, i, j, '1', 0);
}

int main() {
    data_t test;
    scanf("%d %d", &test.plays, &test. distance);
    
    int *n = 0;
    n = loop(test, 0, &n);
    printf("%d", n);
	return 0;
}
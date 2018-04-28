#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int conferir(int quantidade, int matriz[quantidade][10], int resultado[], int i, int j, int k, int contador, int total_V){

    //printf("Matriz[%d][%d]=%d\n",i,j,matriz[i][j]);
    //printf("Resultados: %d\n",resultado[k]);
    if(i==quantidade){
        printf("Total de ganhadores: %d\n",total_V);
    }else{
        if(j==10){
            if(contador==6){
                total_V+=1;
            }
            conferir(quantidade,matriz,resultado,i+1,0,0,0,total_V);
        }else if(k==6){
            conferir(quantidade,matriz, resultado,i,j+1,0,contador,total_V);
        }else{
            if(matriz[i][j]==resultado[k]){
                contador+=1;
                //printf("Contador agr: %d\n",contador);
            }
            conferir(quantidade, matriz, resultado, i, j, k+1, contador, total_V);
        }
    }
}

int ler_resultado(int resultado[], int i){

    if(i==6){
        return;
    }else{
        scanf("%d", &resultado[i]);
        //printf("Resultados: %d\n",resultado[i]);
        ler_resultado(resultado,i+1);
    }
}


int ler_matriz(int quantidade, int matriz[quantidade][10], int i, int j,char virgulas){

    if(i==quantidade){
        return;
    }else{
        scanf("%d%c", &matriz[i][j], &virgulas);
        //printf("Matriz[%d][%d]=%d\n",i,j,matriz[i][j]);
        //printf(":%c\n",virgulas);
        if(virgulas=='\n'){
            ler_matriz(quantidade,matriz,i+1,0,virgulas);
        }else{
            ler_matriz(quantidade,matriz,i,j+1,virgulas);
        }
    }
}


int main() {
    char virgulas;
    int quantidade, resultado[6];
    scanf("%d", &quantidade);
    int matriz[quantidade][10];
    if(quantidade>=0){
        ler_matriz(quantidade, matriz,0,0,virgulas);
        ler_resultado(resultado,0);
        conferir(quantidade,matriz,resultado,0,0,0,0,0);
    }else{
        printf("SEM RESPOSTA");
    }

	return 0;
}
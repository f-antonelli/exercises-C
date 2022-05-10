#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarMatriz(int [][TAM]);
int esMatrizDiagonal(int [][TAM],int);

int main()
{
    int mat[][TAM] = {{4, 0, 0, 0, 0},
        {0, 21, 0, 0, 0},
        {0, 0, 7, 0, 0},
        {0, 0, 0, 19, 0},
        {0, 0, 0, 0, 23},
    };

    printf("*** MATRIZ INICIAL ***\n\n");
    mostrarMatriz(mat);

    esMatrizDiagonal(mat, 5)
        ? printf("\nEs una matriz diagonal.\n")
        : printf("\nNO es una matriz diagonal.\n");

    return 0;
}

void mostrarMatriz(int mat[][TAM])
{
    int i, j;
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
            printf("%4d ", mat[i][j]);

        printf("\n");
    }
}

int esMatrizDiagonal(int mat[][TAM],int ord) {
    int i, j;

    for(i = 0 ; i < ord ; i++){
        for(j = 0 ; j < ord ; j++){
            if (i != j && mat[i][j] != 0)
                return 0;
        }
    }

    return 1;
}

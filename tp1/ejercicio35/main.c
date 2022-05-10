#include <stdio.h>
#include <stdlib.h>
#define TAM 3

void mostrarMatriz(int [][TAM], int);
void matrizTranspuesta(int [][TAM], int, int);

int main()
{
    int mat[][TAM] = {{8, 2, 0},
        {67, 1, 125}
    };

    printf("*** MATRIZ INICIAL ***\n\n");
    mostrarMatriz(mat, 2);

    matrizTranspuesta(mat, 2, 3);

    return 0;
}

void mostrarMatriz(int mat[][TAM], int f)
{
    int i, j;
    for(i = 0; i < f; i++)
    {
        for(j = 0; j < TAM; j++)
            printf("%4d ", mat[i][j]);

        printf("\n");
    }
}

void matrizTranspuesta(int mat[][TAM], int f, int c)
{
    int i, j, newMat[c][f];

    for(i = 0 ; i < f ; i++)
    {
        for(j = 0 ; j < c ; j++)
            newMat[j][i] = mat[i][j];
        }

    printf("\n** MATRIZ TRANSPUESTA **\n\n");
    for(i = 0; i < c; i++)
    {
        for(j = 0; j < f; j++)
            printf("%4d ", newMat[i][j]);

        printf("\n");
    }
}

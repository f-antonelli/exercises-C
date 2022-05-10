#include <stdio.h>
#include <stdlib.h>
#define TAM 3

void mostrarMatriz(int [][TAM]);
void matrizTranspuesta(int mat[][TAM], int ord);

int main()
{
    int mat[][TAM] = {{8, 2, 0},
        {67, 1, 125},
        {12, 14, 1}
    };

    printf("*** MATRIZ INICIAL ***\n\n");
    mostrarMatriz(mat);

    matrizTranspuesta(mat, 3);

    printf("\n*** MATRIZ TRANSPUESTA ***\n\n");
    mostrarMatriz(mat);

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

void matrizTranspuesta(int mat[][TAM], int ord)
{
    int i, j, aux;

    for(i = 0 ; i < ord ; i++)
    {
        for(j = i+1 ; j < ord ; j++)
        {
            if(i != j)
            {
                aux = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = aux;
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#define TAM 3

void mostrarMatriz(int [][TAM]);
int matrizSimetrica(int mat[][TAM], int ord);

int main()
{
    int mat[][TAM] = {{1, 2, 3},
                        {2, 2, 8},
                        {3, 8, 1}
    };

    printf("*** MATRIZ INICIAL ***\n\n");
    mostrarMatriz(mat);

    matrizSimetrica(mat, 3)
        ? printf("\nLa matriz es Simetrica\n")
        : printf("\nLa matriz NO es Simetrica\n");

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

int matrizSimetrica(int mat[][TAM], int ord)
{
    int i, j;

    for(i = 0 ; i < ord ; i++)
    {
        for(j = i+1 ; j < ord ; j++)
        {
            if(i != j && mat[i][j] != mat[j][i])
                return 0;
        }
    }

    return 1;
}

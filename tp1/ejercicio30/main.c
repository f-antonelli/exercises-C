#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarMatriz(int [][TAM]);
void sumDiagPpal(int mat[][TAM], int ord);
void sumDiagSecundaria(int mat[][TAM], int ord);

int main()
{
    int mat[][TAM] = {{4, 12, 43, 1, 3},
        {34, 23, 123, 6, 2},
        {9, 5, 7, 34, 15},
        {56, 34, 32, 19, 10},
        {38, 49, 29, 1, 23},
    };

    printf("*** MATRIZ INICIAL ***\n\n");
    mostrarMatriz(mat);

    printf("\n** LA SUMA DE LA DIAGONAL PRINCIPAL ES **");
    sumDiagPpal(mat, 5);

    printf("\n** LA SUMA DE LA DIAGONAL SECUNDARIA ES **");
    sumDiagSecundaria(mat, 5);

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

void sumDiagPpal(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord; j++)
        {
            if(i == j)
                res += mat[i][j];
        }
    }

    printf("\nEl resultado es: %d\n", res);
}

void sumDiagSecundaria(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord; j++)
        {
            if(j == ord-i-1)
                res += mat[i][j];
        }
    }

    printf("\nEl resultado es: %d\n", res);
}

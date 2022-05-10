#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarMatriz(int [][TAM]);
int esMatrizIdentidad(int [][TAM],int);

int main()
{
    int mat[][TAM] = {{1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
    };

    printf("*** MATRIZ INICIAL ***\n\n");
    mostrarMatriz(mat);

    esMatrizIdentidad(mat, 5)
        ? printf("\nEs una matriz identidad.\n")
        : printf("\nNO es una matriz identidad.\n");

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

int esMatrizIdentidad(int mat[][TAM],int ord) {
    int i, j;

    for(i = 0 ; i < ord ; i++){
        for(j = 0 ; j < ord ; j++){
            if (i != j && mat[i][j] != 0)
                return 0;
            if (i == j && mat[i][j] != 1)
                return 0;
        }
    }

    return 1;
}

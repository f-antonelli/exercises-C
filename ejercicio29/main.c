#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

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

    printf("\n** SUMA TRIANGULO SUP S/ DIAG PRINCIPAL **\n");
    sumElemTSupDP(mat, 5);

    printf("\n** SUMA TRIANGULO SUP S/ DIAG SECUNDARIA **\n");
    sumElemTSupDS(mat, 5);

    printf("\n** SUMA TRIANGULO SUP C/ DIAG PRINCIPAL **\n");
    sumElemTSupConDP(mat, 5);

    printf("\n** SUMA TRIANGULO SUP C/ DIAG SECUNDARIA **\n");
    sumElemTSupConDS(mat, 5);

    printf("\n** SUMA TRIANGULO INF S/ DIAG PRINCIPAL **\n");
    sumElemTInfDP(mat, 5);

    printf("\n** SUMA TRIANGULO INF S/ DIAG SECUNDARIA **\n");
    sumElemTInfDS(mat, 5);

    printf("\n** SUMA TRIANGULO INF C/ DIAG PRINCIPAL **\n");
    sumElemTInfConDP(mat, 5);

    printf("\n** SUMA TRIANGULO INF C/ DIAG SECUNDARIA **\n");
    sumElemTInfConDS(mat, 5);

    return 0;
}



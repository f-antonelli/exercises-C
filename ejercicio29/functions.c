#include <stdio.h>
#include "functions.h"

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

void sumElemTSupDP(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord; j++)
        {
            if (j > i)
                res += mat[i][j];
        }
    }

    printf("\nEl resultado es: %d\n", res);
}

void sumElemTSupDS(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord-i-1; j++)
            res += mat[i][j];
    }

    printf("\nEl resultado es: %d\n", res);
}

void sumElemTSupConDP(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord; j++)
        {
            if (j >= i)
                res += mat[i][j];
        }
    }

    printf("\nEl resultado es: %d\n", res);
}

void sumElemTSupConDS(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord-i; j++)
            res += mat[i][j];
    }

    printf("\nEl resultado es: %d\n", res);
}

void sumElemTInfDP(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord; j++)
        {
            if (j < i)
                res += mat[i][j];
        }
    }

    printf("\nEl resultado es: %d\n", res);
}

void sumElemTInfDS(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord; j++)
        {
            if (j > ord-i-1)
                res += mat[i][j];
        }
    }

    printf("\nEl resultado es: %d\n", res);
}

void sumElemTInfConDP(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord; j++)
        {
            if (j <= i)
                res += mat[i][j];
        }
    }

    printf("\nEl resultado es: %d\n", res);
}

void sumElemTInfConDS(int mat[][TAM], int ord)
{
    int i, j, res = 0;

    for(i = 0; i < ord; i++)
    {
        for(j = 0; j < ord; j++){
            if(j >= ord-i-1)
                res += mat[i][j];
        }
    }

    printf("\nEl resultado es: %d\n", res);
}

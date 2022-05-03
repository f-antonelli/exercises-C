#include <stdio.h>
#include <stdlib.h>

void cargar_matriz(int mat[][TAM], int Dimfila)
{
    int i=0, j=0;
    for(i = 1; i<Dimfila; i++)
    {
        for(j = 0; j<TAM; j++)
        {
            printf("\n Ingrese el valor de la matriz: ");
            scanf("%d",&mat[i][j]);
        }
    }
}

#define MAYOR(X,Y) ((X)>(Y)?(X):(Y))
void triangulo_der(int mat[][TAM], int ord)
{
    int i, j, inij;
    printf("\n Triangulo derecho de la matriz ");
    for (i = 0; i <ord; i++)
    {
        inij = MAYOR(ord-i-1, i);
        printf("\n%*s", (5*inij), "");
        for(j = inij ; j <ord; j++)
        {
            printf("%5d", mat[i][j]);
        }
    }
}

void mostrar_matriz(int mat [][TAM], int fil, int col)
{
    int i,j;
    printf("\n Matriz completa \n\n");
    for(i=0; i<fil; i++)
    {
        for(j=0;j<col;j++)
            printf("%5d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

///diag principal => filas = columnas
///diag secundaria       => columna = ord - fila - 1
void debajo_diag_ppal(int mat[][TAM], int ord)
{
    int f, c;
    printf("\n Matriz resultante debajo diagonal principal \n\n");
    for(f = 1; f<ord; f++)///NO incluyo la diagonal
    {
        for(c = 0; c<f; c++)
        {
            printf("%5d", mat[f][c]);
        }
        printf("\n");
    }
}
void triangulo_sup(int mat[][TAM], int ord)
{
    int i, j;
    printf("\nTriangulo superior de la diagonal principal\n\n");
    for(i = 0; i<ord/2; i++)
    {
        for(j = i+1; j<ord-1-i; j++)
        {
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
}
void triangulo_izq(int mat[][TAM], int ord)
{
    int i,j;
    for(i=1; i<ord-1; i++)
    {
        for(j=0 ; j<i && j<(ord-i-1) ; j++)
            printf("%3d ", mat[i][j]);
        printf("\n");
    }
}
void triangulo_sup2(int mat[][TAM], int ord)
{
    int i,j;
    printf("\nTriangulo_superior formateado\n");
    for(i=0; i<ord/2; i++)
    {
        printf("%*s",3*i, "");
        ///printf("%3s", "");
        for(j=i+1;j<(ord-i-1);j++)
            printf("%3d", mat[i][j]);
        printf("\n");
    }
}

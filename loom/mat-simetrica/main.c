#include <stdio.h>
#include <stdlib.h>

#define ERR 1
#define OK 0

void cargarMatriz(int **m, int *f, int *c);
void mostrarMatriz(int **m, int *f, int *c);
int esSimetrica(int **mat, int *f, int *c);

int main()
{
    int f, c, x, **mat;

    printf("Ingrese un numero de filas: ");
    scanf("%d", &f);

    printf("Ingrese un numero de columnas: ");
    scanf("%d", &c);

    if(f != c)
    {
        printf("La matriz no es cuadrada, por ende tampoco simetrica.\n");
        return ERR;
    }

    mat = (int**)malloc(f*sizeof(int*));

    for(x = 0 ; x < f ; x++)
        mat[x] = (int*)malloc(c*sizeof(int));

    cargarMatriz(mat, &f, &c);
    mostrarMatriz(mat, &f, &c);

    esSimetrica(mat, &f, &c)
    ? printf("\nLa matriz es simetrica.\n")
    : printf("\nLa matriz NO es simetrica.\n");

    return 0;
}

void cargarMatriz(int **m, int *f, int *c)
{
    int i, j;

    for (i = 0 ; i < *f ; i++)
    {
        for (j = 0 ; j < *c ; j++)
        {
            printf("Ingrese un numero para [%d][%d]: ", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }
}

void mostrarMatriz(int **m, int *f, int *c)
{
    int i, j;

    printf("\n**MATRIZ DE %dx%d**\n", *f, *c);
    for (i = 0 ; i < *f ; i++)
    {
        for (j = 0 ; j < *c ; j++)
            printf("%3d ", m[i][j]);

        printf("\n");
    }
}

int esSimetrica(int **mat, int *f, int *c)
{
    int i, j;
    for (i = 0 ; i <= (*f/2) ; i++)
    {
        for (j = i+1 ; j <= *f-1 ; j++)
        {
            if(mat[i][j] != mat[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}

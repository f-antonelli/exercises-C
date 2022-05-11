#include <stdio.h>
#include <stdlib.h>

void cargarVector(int *arr, int *ce);
int vectoresDisjuntos(int *arr1, int *arr2, int *ceV1, int *ceV2);

int main()
{
    int *arr1, *arr2, cantV1, cantV2;

    printf("Cuantos numeros desea ingresar en el 1er vector: ");
    scanf("%d", &cantV1);

    arr1 = (int*)malloc(cantV1*sizeof(int));
    cargarVector(arr1, &cantV1);

    printf("Cuantos numeros desea ingresar en el 2do vector: ");
    scanf("%d", &cantV2);

    arr2 = (int*)malloc(cantV1*sizeof(int));
    cargarVector(arr2, &cantV2);

    vectoresDisjuntos(arr1, arr2, &cantV1, &cantV2)
        ? printf("\nLos vectores son conjuntos disjuntos.\n")
        : printf("\nLos vectores no son conjuntos disjuntos.\n");

    return 0;
}

void cargarVector(int *arr, int *ce)
{
    int i;

    for(i = 0 ; i < *ce ; i++)
    {
        printf("Ingrese un numero [%d]: ", i+1);
        scanf("%d", arr+i);
    }
}

int vectoresDisjuntos(int *arr1, int *arr2, int *ceV1, int *ceV2)
{
    int i, j;

    for(i = 0 ; i < *ceV1 ; i++)
    {
        for(j = 0 ; j < *ceV2 ; j++)
        {
            if(*(arr1+i) == *(arr2+j))
                return 0;
        }
    }

    return 1;
}

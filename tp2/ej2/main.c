#include <stdio.h>
#include <stdlib.h>
void mostrarArray(int *arr, int *ce);
void buscarEnArray(int *arr, int *num, int *ce);

int main()
{
    int cantElem = 5, num;
    int arr[] = {1, 3, 55, 34, 23};

    mostrarArray(arr, &cantElem);

    printf("\nElija uno de los numeros anteriores: ");
    scanf("%d", &num);

    buscarEnArray(arr, &num, &cantElem);

    return 0;
}

void mostrarArray(int *arr, int *ce)
{
    int i;

    for (i = 0 ; i < *ce ; i++)
        printf("%i ", *(arr+i));

    printf("\n");
}

void buscarEnArray(int *arr, int *num, int *ce)
{
    int i;

    for(i = 0 ; i < *ce ; i++)
        if(*num == *(arr+i))
            printf("La direccion de memoria en la que se encuentra el numero %d es: %x",*num, &arr+i);
}

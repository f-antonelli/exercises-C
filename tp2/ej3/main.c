#include <stdio.h>
#include <stdlib.h>

void ingresarNumeros(int *arr, int *ce);
void mostrarArr(int *arr, int *ce);
float calcSumYProm(int *arr, int *ce, long int *suma);


int main()
{
    int *arr, cantNum;
    long int resSuma = 0;

    printf("Cuantos numeros desea ingresar: ");
    scanf("%d", &cantNum);

    arr = (int*)malloc(cantNum*sizeof(int));

    ingresarNumeros(arr, &cantNum);

    mostrarArr(arr, &cantNum);

    printf("\nEl promedio de los elementos de array es: %2.f", calcSumYProm(arr, &cantNum, &resSuma));

    return 0;
}

void ingresarNumeros(int *arr, int *ce)
{
    int i = 0;

    while(i < *ce)
    {
        printf("Ingrese un numero entero: ");
        scanf("%d", arr+i);
        i++;
    }
}

void mostrarArr(int *arr, int *ce)
{
    int i;

    printf("\n***Elementos del array***\n");
    for(i = 0 ; i < *ce ; i++)
        printf("[%d] ", *(arr+i));

    printf("\n");
}

float calcSumYProm(int *arr, int *ce, long int *suma)
{
    int i;
    float resProm;

    for(i = 0 ; i < *ce ; i++)
        *suma += *(arr+i);

    printf("\nLa suma de los elementos de array es: %li", *suma);
    resProm = *suma;

    return resProm/(*ce);
}

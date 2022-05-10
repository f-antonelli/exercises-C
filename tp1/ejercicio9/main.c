#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int num1, num2;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);

    do {
        printf("Ingrese otro numero (!== 0): ");
        scanf("%d", &num2);
    } while(num2 == 0);

    cociente(num1, num2);

    return 0;
}



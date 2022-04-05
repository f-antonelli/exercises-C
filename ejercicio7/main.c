#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main()
{
    int num;

    printf("Ingrese un numero natural: ");
    scanf("%d", &num);

    divisores(num);

    return 0;
}

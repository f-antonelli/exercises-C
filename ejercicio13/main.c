#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool esPrimo(int);

int main()
{
    int num;

    printf("Ingrese un numero natural: ");
    scanf("%d", &num);

    esPrimo(num)
        ? printf("El numero %d es primo", num)
        : printf("El numero %d no es primo", num);

    return 0;
}

bool esPrimo(int num) {
    int i, aux = 0;

    for(i = num; i >= 1; i--) {
        if(num % i == 0)
            aux++;
    }

    return (aux == 2) ? 1 : 0;
}

#include <stdio.h>
#include <stdlib.h>

void sumaPrimerosNaturales(int);

int main()
{
    int num;

    printf("Ingrese un numero natural: ");
    scanf("%d", &num);

    sumaPrimerosNaturales(num);

    return 0;
}

void sumaPrimerosNaturales(int num) {
    int i, res = 0;

    for(i = num; i >= 1; i--)
        res += i;

    printf("La suma de los primeros numeros naturales es: %d", res);
}

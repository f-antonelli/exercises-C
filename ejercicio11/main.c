#include <stdio.h>
#include <stdlib.h>

void sumaPrimerosNaturalesPares(int);

int main()
{
    int num;

    printf("Ingrese un numero natural: ");
    scanf("%d", &num);

    sumaPrimerosNaturalesPares(num);

    return 0;
}

void sumaPrimerosNaturalesPares(int num) {
    int i, res = 0;

    for(i = num; i >= 1; i--) {
        if(i % 2 == 0)
            res += i;
    }

    printf("La suma de los primeros numeros naturales PARES es: %d", res);
}

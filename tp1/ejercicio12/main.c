#include <stdio.h>
#include <stdlib.h>

void sumaPrimerosNaturalesParesMenosN(int);

int main()
{
    int num;

    printf("Ingrese un numero natural: ");
    scanf("%d", &num);

    sumaPrimerosNaturalesParesMenosN(num);

    return 0;
}

void sumaPrimerosNaturalesParesMenosN(int num) {
    int i, res = 0;

    for(i = num-1; i >= 1; i--) {
        if(i % 2 == 0)
            res += i;
    }

    printf("La suma de los primeros numeros naturales PARES (menos %d) es: %d",num, res);
}

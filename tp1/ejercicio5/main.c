#include <stdio.h>
#include <stdlib.h>

void fibonacci(int num);

int main()
{
    int num;

    do {
        printf("Ingrese un numero:");
        scanf("%d", &num);
    } while (num < 0);

    fibonacci(num);

    return 0;
}

void fibonacci(int num) {
    int auxA = 1, auxB = 1, res = 0;

    while (res < num) {
        res = auxA + auxB;
        auxA = res - auxA;
        auxB = res;
    }

    (res == num)
        ? printf("El numero %d se encuentra en la serie de Fibonacci.", res)
        : printf("No se encontro en la serie de Fibonacci");
}


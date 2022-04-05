#include <stdio.h>
#include <stdlib.h>

void factorial(int n);

int main()
{
    int num;

    printf("Ingrese un numero: ");
    scanf("%d", &num);

    factorial(num);

    return 0;
}

void factorial(int num) {
    int i;
    double res = 1;

    if (num < 0) {
         printf("No existe el factorial de un numero negativo");
    }
    else {
        for(i = num; i >= 2; i--)
            res *= i;

        printf("El factorial de %d es: %d", num, res);
    }
}

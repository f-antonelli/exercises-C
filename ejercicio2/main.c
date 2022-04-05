#include <stdio.h>
#include <stdlib.h>

void combinatoria(int n, int m);
int factorial(int num);

int main()
{
    int m, n;

    do {
        printf("Ingrese un numero: ");
        scanf("%d", &n);
    } while(n < 0);


    do {
        printf("Ingrese otro numero (mayor al anterior): ");
        scanf("%d", &m);
    } while (m < n);


    combinatoria(n, m);

    return 0;
}



void combinatoria(int n, int m) {
    int res = 0;

    res = factorial(m) / (factorial(n) * factorial(m-n));

    printf("El combinatorio es: %d", res);
}

int factorial(int num) {
    int i, res = 1;

    for(i = num; i >= 2; i--)
        res *= i;

    return res;
}

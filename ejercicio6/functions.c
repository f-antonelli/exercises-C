#include <stdio.h>

double potencia(int base, int exponente) {
    int i;
    double res = base;

    for (i = 1; i < exponente; i++)
        res *= base;

    return res;
}

double factorial(int num) {
    int i, res = 1;

    for(i = num; i > 1; i--)
        res *= i;

    return res;
}

double obtenerSeno(int num, int tol){
    int i = 1, aux = 3;
    double res = num, tolTest = 0;

    do {
        printf("%lf\n", res);

        (i % 2 == 0)
            ?   (res += potencia(num, aux) / factorial(aux))
            :   (res -= potencia(num, aux) / factorial(aux));

        aux += 2;
        i++;
        tolTest = (res < 0) ? res *= -1 : res;
        printf("%d\n", tol);

        printf("tol test: %lf\n\n", tolTest);

    } while (tolTest < tol);

    return res;
}

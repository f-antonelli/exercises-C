#include <stdio.h>
#include <stdlib.h>

double factorial (int);
double potencia(int, int);
double exponencial (int, float);

int main()
{
    int num;
    float tol;

    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    printf("Ingrese un tolerancia: ");
    scanf("%f", &tol);

    printf("El exponencial es: %lf", exponencial(num, tol));

    return 0;
}

double exponencial (int num, float tol) {
    double res = 1;
    int i;

    do {

    }
}

double factorial (int num) {
    int i, res = 1;

    for (i = 1; i <= num; i++)
        res*=i;

    return res;
}

double potencia(int base, int exponencial) {
    int i, res = base;

    for(i = 1; i < exponencial; i++)
        res *= base;

    return exponencial == 0 ? 1 : res;
}

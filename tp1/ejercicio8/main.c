#include <stdio.h>
#include <stdlib.h>

void productoPorSumas(int, int);

int main()
{
    int n1, n2;

    do {
        printf("Ingrese un numero natural: ");
        scanf("%d", &n1);
    } while (n1 < 0);

    do {
        printf("Ingrese otro numero natural: ");
        scanf("%d", &n2);
    } while (n1 < 0);

    productoPorSumas(n1, n2);

    return 0;
}

void productoPorSumas(int n1, int n2){
    int i, res = 0;

    for(i = n1; i >= 1; i--)
        res += n2;

    printf("El producto de ambos numeros es: %d", res);
}

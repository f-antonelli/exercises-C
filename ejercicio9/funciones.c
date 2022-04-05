#include <stdio.h>

void cociente(int num1, int num2) {
    int cociente = 0;

    do {
        num1 = num1 - num2;
        cociente++;
    } while(num1 >= num2);

    printf("\nEl cociente de la division es: %d\n", cociente);
    printf("El resto de la division es: %d\n", num1);
}

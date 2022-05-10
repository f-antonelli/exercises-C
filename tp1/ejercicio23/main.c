#include <stdio.h>
#include <stdlib.h>
#define TAM 6

void insertarEnVector(int *, int, int);
void mostarVector(int *v, int ce);

int main()
{
    int num, vec[TAM] = {3, 5, 7, 9, 10, 23};

    printf("Ingrese un numero a insertar: ");
    scanf("%d", &num);

    insertarEnVector(vec, num, TAM);
    mostarVector(vec, TAM);

    return 0;
}

void insertarEnVector(int *v, int num, int ce) {
    int i, pos = 0;

    while (num >= *(v+pos) && pos < ce)
        pos++;

    for(i = ce; i >= pos; i--)
        *(v+i+1) = *(v+i);

    *(v+pos) = num;
}

void mostarVector(int *v, int ce) {
    int i;
    printf("- VECTOR -\n");

    for (i = 0; i <= ce; i++)
        printf("%i ", *(v+i));
}

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void insertarEnVector(int *, int, int);
void mostarVector(int *, int);

int main()
{
    int vec[TAM]={0}, num, pos;

    mostarVector(vec, TAM);

    printf("\n\nIngrese un numero: ");
    scanf("%d", &num);

    do {
        printf("Elija una posicion del vector [1 a 10]: ");
        scanf("%d", &pos);
    }while (pos < 1 || pos > 10);

    insertarEnVector(vec, num, pos);
    mostarVector(vec, TAM);

    return 0;
}

void insertarEnVector(int *v, int num, int pos) {
    *(v+pos-1) = num;
}

void mostarVector(int *v, int ce) {
    int i;
    printf("- VECTOR -\n");

    for (i = 0; i < ce; i++)
        printf("%i ", *(v+i));
}

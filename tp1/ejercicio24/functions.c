#include <stdio.h>
#include <stdbool.h>

bool validarNum(int *v, int num, int ce) {
    int i;
    bool exist = false;

    for(i = 0; i < ce; i++) {
        if (num == *(v+i))
            exist = true;
    }

    return exist;
}

void eliminarElemento(int *v, int num, int *ce) {
    int i, pos = 0;

    while (num != *(v+pos))
        pos++;

    for(i = pos; i < *ce; i++)
        *(v+i) = *(v+i+1);

    *ce = *ce-1;
}

void mostrarVector(int *v, int *ce) {
    int i;

    printf("*** VECTOR ***\n");
    for(i = 0; i < *ce; i++)
        printf("%d ", *(v+i));
}

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

void mostrarVector(int *v, int *ce) {
    int i;

    printf("*** VECTOR ***\n");
    for(i = 0; i < *ce; i++)
        printf("%d ", *(v+i));
}

int numEnVector(int *v, int num, int *ce) {
    int i, res = 0;

    for (i = 0; i < *ce; i++) {
        if(*(v+i) == num)
            res++;
    }

    return res;
}

void eliminarNumVector(int *v, int num, int *ce){
    int i, j, pos = 0, cantNum;

    cantNum = numEnVector(v, num, ce);

    for(j = 0; j < cantNum; j++){
        while (num != *(v+pos))
            pos++;

        for(i = pos; i < *ce; i++)
            *(v+i) = *(v+i+1);

        *ce = *ce-1;
    }

}

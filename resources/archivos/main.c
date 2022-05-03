#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    fp = fopen("archivos.dat", "wb");

    if (fp == NULL) {
        printf("El archivo no logro abrirse");
        system("pause");
        exit(-1);
    }

    fclose(fp);
    return 0;
}

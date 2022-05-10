#include "func.h"


int main()
{
    float arr[10];
    int cantNum = 5, opc = 0, ret;

    llenarArray(arr, &cantNum);

    printf("\nLa cantidad de elementos ingresados es: %d\n\n", cantNum);

    do
    {
        opc = menu(MENU_MSJ, MENU_OPC);

        switch(opc)
        {
        case '1':
            printf("\nEl minimo es: %.2f.\n", buscarMinimo(arr, &cantNum));
            break;
        case '2':
            printf("\nEl promedio de los numeros pares es: %.2f.\n", promPares(arr, &cantNum));
            break;
        case '3':
            invertirArr(arr, &cantNum);
            printf("\nOrden inverso\n");
            mostrarArray(arr, &cantNum);
            break;
        case '4':
            ret = grabarArchivo(arr);
            break;
        }
    }
    while(opc != '4');

    return ret;
}

int grabarArchivo(float *arr)
{
    FILE *fp;

    fp = fopen("arr.bin", "wb");

    if(!fp)
    {
        printf("Fallo la apertura del archivo.\n");
        return ERR_FILE;
    }

    fwrite(arr, sizeof(arr), 1, fp);
    fclose(fp);

    return TODO_OK;
}


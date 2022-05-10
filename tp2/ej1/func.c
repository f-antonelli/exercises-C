#include <stdio.h>
#include <string.h>
#include <ctype.h>

int menu(const char *msj, const char *opc)
{
    char opta;
    int priVez = 1;

    do
    {
        printf("%s%s",
               priVez ? priVez = 0, "" : "ERROR - Opcion no valida.\n",
               msj);
        fflush(stdin);
        scanf("%c", &opta);
    }
    while(strchr(opc,opta) == NULL);

    return opta;
}

char funcExit()
{
    char exit;
    do
    {
        printf("Salir (S/N): ");
        fflush(stdin);
        scanf("%c", &exit);
        exit = toupper(exit);
    }
    while(exit != 'S' && exit != 'N');

    return exit;
}

void llenarArray(float *arr, int *elem)
{
    int i = 0;
    char exit;

    do
    {
        printf("Ingrese un numero (max %d): ", *elem);
        scanf("%f", (arr+i));
        i++;

        if(i != *elem)
            exit = funcExit();
    }
    while(i < *elem && exit != 'S');

    *elem = i;
}

void mostrarArray(float *arr, int *ce)
{
    int i;

    for(i = 0; i < *ce ; i++)
        printf("%.2f - ", arr[i]);

    printf("\n");
}

float buscarMinimo(float *arr, int *ce)
{
    int i;
    float min;

    for(i = 0 ; i < *ce ; i++)
    {
        if(i == 0)
            min = *(arr+i);
        else
        {
            if(min > *(arr+i))
                min = *(arr+i);
        }
    }

    return min;
}

float promPares(float *arr, int *ce)
{
    int i, aux = 0;
    float res;

    for(i = 0 ; i < *ce ; i++)
    {
        if(i % 2 != 0)
        {
            res += *(arr+i);
            aux++;
        }
    }

    return res/aux;
}

void invertirArr(float *arr, int *ce)
{
    int i;
    float aux;

    for(i = 0 ; i < *ce/2 ; i++)
    {
        aux = *(arr+i);
        *(arr+i) = *(arr+*ce-i-1);
        *(arr+*ce-i-1) = aux;
    }
}

#include "main.h"


int main()
{
    char opcion;

    do
    {
        opcion = menuConError(MENU_MSJ, MENU_OPC);

        switch(opcion)
        {
        case 'A':
            printf("Ingresaste %c", opcion);
            break;
        case 'B':
            printf("Ingresaste %c", opcion);
            break;
        case 'C':
            printf("Ingresaste %c", opcion);
            break;
        case 'M':
            printf("Ingresaste %c", opcion);
            break;
        case 'L':
            printf("Ingresaste %c", opcion);
            break;
        case 'S':
            printf("Ingresaste %c", opcion);
            break;
        }
    }
    while(opcion != 'S');

    return 0;
}

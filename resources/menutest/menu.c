#include <stdio.h>
#include <string.h>
#include <ctype.h> //por las funciones tolower/toupper


char menuSinError(const char *msj, const char *opc)
{
    char opta;

    do
    {
        printf("%s", msj);
        fflush(stdin);
        scanf("%c", &opta);
    }
    while(strchr(opc,opta) == NULL);

    return opta;
}

char menuConError(const char *msj, const char *opc)
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

//void probarMenu(void)
//{
//    char opcion;
//
//    opcion = menuConError("Graba? (S/N): ", "SNsn");
//    printf("Opcion elegida: %c\n", opcion);
//
//    do
//    {
//        opcion = menuConError("Elija una opcion\n\n"
//                              "A - Alta\n"
//                              "B - Baja\n"
//                              "C - Consulta\n"
//                              "M - Modificaicon\n"
//                              "L - Listado\n"
//                              "S - Salir\n"
//                              "--> ",
//                              "ABMCSLabmcsl");
//
//        opcion = toupper(opcion);
//        printf("Opcion elegida: %c\n", opcion);
//
//    }
//    while(opcion != 'S');
//}

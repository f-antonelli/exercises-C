#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERR_FILE 1
#define TODO_OK 0
#define MENU_MSJ "\nElija una opcion\n\n"                                                             \
                              "1 - Buscar el minimo elemento\n"                                     \
                              "2 - Calcular el promedio de los valores de las posiciones pares\n"   \
                              "3 - Mostrarlo en orden inverso\n"                                    \
                              "4 - Salir\n"                                                         \
                              "--> "

#define MENU_OPC "1234"

int menu(const char *msj, const char *opc);
char funcExit();
void llenarArray(float *arr, int *elem);
void mostrarArray(float *arr, int *ce);
float buscarMinimo(float *arr, int *ce);
float promPares(float *arr, int *ce);
void invertirArr(float *arr, int *ce);
int grabarArchivo(float *arr);


#endif // FUNC_H_INCLUDED

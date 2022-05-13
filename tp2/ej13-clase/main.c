#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    FILE *pa, *pb;

    ///crear archivos
    crear_archivos();

    ///abrir archivos
    pa = fopen("archivos/archivo_empleados.bin","r+b");
    pb = fopen("archivos/archivo_estudiantes.bin","rb");

    if (!pa || !pb){
        printf("Error de archivos");
    }


    ///mostrar archivos
    mostrar_archivos();

    ///apareo archivos
    apareo_archivos(pa, pb);

    ///mostrar archivos
    mostrar_archivos();

    return 0;
}

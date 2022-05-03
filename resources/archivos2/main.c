#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia, mes, anio;
} tFecha;

typedef struct
{
    long dni;
    char apyn[36];
    char categoria;
    tFecha fecIngreso;
    float sueldo;
} tEmpleado;

int crearArchivo(char *);

int main()
{
    crearArchivo("hola.bin");
    return 0;
}

int crearArchivo(char *nombreArchivo)
{
    tEmpleado vectorEmpleados[] =
    {
        {44444444, "Persona Cuatro", 'A', {1, 4, 2004}, 44000.4F},
        {22222222, "Persona Dos", 'B', {1, 2, 2002}, 22000.2F},
        {33333333, "Persona Tres", 'B', {1, 3, 2003}, 33000.3F},
        {55555555, "Persona Cinco", 'A', {1, 5, 2005}, 55000.5F},
        {11111111, "Persona Uno", 'C', {1, 1, 2001}, 11000.1F}
    };

    FILE *fp = fopen(nombreArchivo, "wb");

    if(fp)
    {
        fwrite(vectorEmpleados, sizeof(vectorEmpleados), 1, fp);
        fclose(fp);
        return 0;
    }
    return -2;
}

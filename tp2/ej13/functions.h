#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_ARCHIVO 1
#define OK 0

typedef struct
{
    long dni;
    char apellido[20];
    char nombre[20];
    double sueldo;
} Empleados;

typedef struct
{
    long dni;
    char apellido[20];
    char nombre[20];
    float promedio;
} Estudiantes;

int crearArchivoEmp(const char *nomArchivo);
int crearArchivoEst(const char *nomArchivo);
int mostrarEmpleados();
int mostrarEstudiantes();
int mergeFiles(const char *archEmp, const char *archEst);

#endif // FUNCTIONS_H_INCLUDED

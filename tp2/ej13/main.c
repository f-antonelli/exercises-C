#include "functions.h"

int main()
{
    int resp;

    resp = crearArchivoEmp("files/empleados.bin");

    puts("Archivo inicial Empleados");
    resp = mostrarEmpleados();

    resp = crearArchivoEst("files/estudiantes.bin");

    puts("\nArchivo inicial Estudiantes");
    resp = mostrarEstudiantes();

    mergeFiles("files/empleados.bin", "files/estudiantes.bin");

    puts("\nArchivo Final Empleados");
    resp = mostrarEmpleados();

    return resp;
}


#include "functions.h"

int crearArchivoEmp(const char *nomArchivo)
{
    FILE *archivo = fopen(nomArchivo, "wb");

    if(!archivo)
    {
        printf("El archivo %s no se pudo crear.\n", nomArchivo);
        return ERR_ARCHIVO;
    }

    Empleados empleados[]=
    {
        { 41239845, "Gomez", "Micaela", 822312 },
        { 40389732, "Pilou", "Roque", 945068 },
        { 20913832, "Pochoclo", "Felipe", 43590 },
        { 90458763, "Totora", "Hernesto", 329875 }
    };

    fwrite(&empleados, sizeof(Empleados), 4, archivo);

    fclose(archivo);

    return OK;
}

int crearArchivoEst(const char *nomArchivo)
{
    FILE *archivo = fopen(nomArchivo, "wb");

    if(!archivo)
    {
        printf("El archivo %s no se pudo crear.\n", nomArchivo);
        return ERR_ARCHIVO;
    }

    Estudiantes estudiantes[]=
    {
        { 41239845, "Gomez", "Micaela", 8.6 },
        { 40389732, "Pilou", "Roque", 7 },
        { 20913832, "Pochoclo", "Felipe", 4.2 },
        { 90458763, "Totora", "Hernesto", 5.3 }
    };

    fwrite(&estudiantes, sizeof(Estudiantes), 4, archivo);

    fclose(archivo);

    return OK;
}

int mostrarEmpleados()
{
    FILE *archivo = fopen("files/empleados.bin", "rb");

    if(!archivo)
    {
        printf("El archivo %s no se pudo leer.\n", "empleados.bin");
        return ERR_ARCHIVO;
    }

    Empleados empleados;

    fread(&empleados, sizeof(Empleados), 1, archivo);
    printf("\n DNI      APELLIDO             NOMBRE               SUELDO\n");
    printf("-------------------------------------------------------------\n");
    while(!feof(archivo))
    {
        printf("%9li %-20s %-20s%10.2f\n",
               empleados.dni,
               empleados.apellido,
               empleados.nombre,
               empleados.sueldo);
        fread(&empleados, sizeof(Empleados), 1, archivo);
    }

    fclose(archivo);

    return OK;
}

int mostrarEstudiantes()
{
    FILE *archivo = fopen("files/estudiantes.bin", "rb");

    if(!archivo)
    {
        printf("El archivo %s no se pudo leer.\n", "estudiantes.bin");
        return ERR_ARCHIVO;
    }

    Estudiantes estudiantes;

    fread(&estudiantes, sizeof(Estudiantes), 1, archivo);
    printf("\n DNI      APELLIDO             NOMBRE               PROMEDIO\n");
    printf("------------------------------------------------------------\n");
    while(!feof(archivo))
    {
        printf("%9li %-20s %-20s%9.2f\n",
               estudiantes.dni,
               estudiantes.apellido,
               estudiantes.nombre,
               estudiantes.promedio);
        fread(&estudiantes, sizeof(Estudiantes), 1, archivo);
    }

    fclose(archivo);

    return OK;
}

int mergeFiles(const char *archEmp, const char *archEst)
{
    int comparar;

    FILE *arEmpleados = fopen(archEmp, "rb");

    if(!arEmpleados)
    {
        printf("El archivo %s no se pudo leer.\n", archEmp);
        return ERR_ARCHIVO;
    }

    FILE *arEstudiantes = fopen(archEst, "rb");

    if(!arEstudiantes)
    {
        printf("El archivo %s no se pudo leer.\n", archEst);
        return ERR_ARCHIVO;
    }

    FILE *arEmpleadosTemp = fopen("files/emptemporal.bin", "wb");

    if(!arEmpleadosTemp)
    {
        printf("El archivo %s no se pudo crear.\n", "emptemporal");
        return ERR_ARCHIVO;
    }

    Empleados emp;
    Estudiantes est;

    fread(&emp, sizeof(Empleados), 1, arEmpleados);
    fread(&est, sizeof(Estudiantes), 1, arEstudiantes);

    while(!feof(arEmpleados) && !feof(arEstudiantes))
    {
        comparar = strcmp(emp.apellido, est.apellido);

        if(comparar == 0)
        {
            if(est.promedio >= 7)
                emp.sueldo += emp.sueldo*0.0728;
        }
            fwrite(&emp, sizeof(Empleados), 1, arEmpleadosTemp);
            fread(&est, sizeof(Estudiantes), 1, arEstudiantes);
            fread(&emp, sizeof(Empleados), 1, arEmpleados);
    }

    fclose(arEmpleados);
    fclose(arEstudiantes);
    fclose(arEmpleadosTemp);

    remove(archEmp);
    rename("files/emptemporal.bin", archEmp);

    return OK;
}

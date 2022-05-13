#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    long dni;
    char apellido[40];
    char nombre[40];
    double sueldo;
}t_empleado;

typedef struct{
    long dni;
    char apellido[40];
    char nombre[40];
    float promedio;
}t_estudiante;

///prototipos de funciones
int crear_archivos();
int mostrar_archivos();

void apareo_archivos(FILE *pa, FILE *pb);

#endif // FUNCIONES_H_INCLUDED

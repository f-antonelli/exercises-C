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

//int leerYMostrarArchivo(char *);
//void mostrarEmpleado(const tEmpleado *);
int buscarPorDNI(FILE *, tEmpleado *, int);

int main()
{
    int numDNI;
    tEmpleado pe;

    printf("Ingrese un numero DNI: ");
    scanf("%d", &numDNI);

    FILE *fp = fopen("hola.bin", "rb");

    if(!fp)
    {
        return - 1;
    }

    buscarPorDNI(fp, &pe, numDNI);

    return 0;
}

//int leerYMostrarArchivo(char *nombreArchivo)
//{
//    tEmpleado emp;
//
//    FILE *fp = fopen(nombreArchivo, "rb");
//
//    if(!fp)
//    {
//        return - 1;
//    }
//
//    mostrarEmpleado(NULL);
//    fread(&emp, sizeof(tEmpleado), 1, fp);
//
//    while(!feof(fp))
//    {
//        mostrarEmpleado(&emp);
//        fread(&emp, sizeof(tEmpleado), 1, fp);
//    }
//    fclose(fp);
//    return 0;
//}
//
//void mostrarEmpleado(const tEmpleado *emp)
//{
//    if(!emp)
//    {
//        printf("DNI      NOMBRE Y APELLIDO                  CAT FEC. ING     SUELDO    \n");
//        printf("-------- ---------------------------------- --- ------------ ----------\n");
//        return;
//    }
//
//    printf("%08ld %-*.*s %c  %02d/%02d/%04d %10.2f\n", emp->dni,
//           sizeof(emp->apyn)-1,
//           sizeof(emp->apyn)-1,
//           emp->apyn,
//           emp->categoria,
//           emp->fecIngreso.dia,
//           emp->fecIngreso.mes,
//           emp->fecIngreso.anio,
//           emp->sueldo);
//}

int buscarPorDNI(FILE *fp, tEmpleado *pe, int dni)
{
    int flag = 0;

    fread(&pe, sizeof(tEmpleado), 1, fp);
    printf("llegue aca?");
    while(!feof(fp)){
        if(dni == pe->dni)
        {
            printf("esta en el code");
            flag++;
        }
        fread(&pe, sizeof(tEmpleado), 1, fp);
    }
    if(flag == 0)
        printf("No existe alguien con ese dni\n");

    fclose(fp);
    return 0;
}

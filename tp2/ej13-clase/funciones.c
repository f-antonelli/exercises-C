#include <stdio.h>
#include "funciones.h"

/**********************************************/
int crear_archivos()
{
    FILE *pa, *pb;

    t_empleado v_empleados[] = {
        {1, "apellido", "nombre", 100.1 },
        {3, "apellido", "nombre", 100.3 },
        {4, "apellido", "nombre", 100.4 },
        {5, "apellido", "nombre", 100.5 },
        {7, "apellido", "nombre", 100.7 },
        {8, "apellido", "nombre", 100.8 }
    };

    t_estudiante v_estudiantes[] = {
        {1, "apellido", "nombre", 7.5 },
        {2, "apellido", "nombre", 7.5 },
        {4, "apellido", "nombre", 7.5 },
        {6, "apellido", "nombre", 7.5 },
        {8, "apellido", "nombre", 7.5 },
        {9, "apellido", "nombre", 7.5 }
    };

    pa = fopen("archivos/archivo_empleados.bin","wb");
    pb = fopen("archivos/archivo_estudiantes.bin","wb");

    if (!pa || !pb){
        printf("Error en la creacion de archivos");
    }

    fwrite(&v_empleados, sizeof(v_empleados),1,pa);
    fwrite(&v_estudiantes, sizeof(v_estudiantes),1,pb);

    fclose(pa);
    fclose(pb);

    return 0;
}

/**********************************************/
int mostrar_archivos()
{
    return 1;
}

/**********************************************/
void apareo_archivos(FILE *pa, FILE *pb)
{
    t_empleado empleado;
    t_estudiante estudiante;

    fread(&empleado, sizeof(t_empleado), 1, pa);
    fread(&estudiante, sizeof(t_estudiante), 1, pb);

    while(!feof(pa) && !feof(pb)) {
        if(empleado.dni == estudiante.dni) {
            ///actualizar el archivo de empleados...
            if(estudiante.promedio >=7) {
                empleado.sueldo *= 1.0728;
                fseek(pa, -1L * sizeof(t_empleado), SEEK_CUR);
                fwrite(&empleado, sizeof(t_empleado), 1, pa);
                fseek(pa, 0L, SEEK_CUR);
            }

            fread(&empleado, sizeof(t_empleado), 1, pa);
            fread(&estudiante, sizeof(t_estudiante), 1, pb);
        } else {
            if(empleado.dni < estudiante.dni) {
                fread(&empleado, sizeof(t_empleado), 1, pa);
            } else {
                fread(&estudiante, sizeof(t_estudiante), 1, pb);
            }
        }
    }

    fclose(pa);
    fclose(pb);
}

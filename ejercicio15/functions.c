#include "functions.h"

int esFechaValida(tFecha* f, int *diasMes) {
    return f->anio >= A_MIN && f->anio <= A_MAX &&
           f->mes >= 1 && f->mes <= 12 &&
           f->dia >= 1 &&
           (f->dia <= *(diasMes+f->mes-1) || (BISIESTO(f->anio) && f->mes == 2 && f->dia == 29));
}

void diaSiguiente(tFecha *f, int *diasMes) {
    if(f->dia < diasMes[f->mes-1])
        f->dia++;

    if(f->dia == diasMes[f->mes-1]){
        f->dia = 1;
        f->mes++;
        if (f->mes > 12){
            f->mes = 1;
            f->anio++;
        }
    }

    if(f->dia == 29 && BISIESTO(f->anio) && f->mes == 2){
        f->dia = 1;
        f->mes++;
    }

    printf("El dia siguiente es: %d/%d/%d", f->dia, f->mes, f->anio);
}

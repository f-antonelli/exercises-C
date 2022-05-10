#include "functions.h"

int esFechaValida(tFecha* f) {
    if(f->anio >= A_MIN && f->anio <= A_MAX)
        if(f->mes >= 1 && f->mes <= 12)
            if(f->dia >= 1 && esDiaValido(f))
                return 1;

    return 0;
}

int esBisiesto(int *anio) {
    return *anio % 4 == 0 || (*anio % 100 == 0 && *anio % 400 != 0);
}

int esDiaValido(tFecha *f) {
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (esBisiesto(&f->anio) && f->mes == 2) return 1;

    return (f->dia <= diasMes[f->mes-1]) ? 1 : 0;
}


#include <stdio.h>
#include <stdlib.h>
#define A_MIN 1600
#define A_MAX 5000
#define BISIESTO(A) (A % 4 == 0 || (A % 100 == 0 && A % 400 != 0))

typedef struct {
    int dia, mes, anio;
} tFecha;

int esFechaValida(tFecha *, int *);
int esBisiesto(int *);
void sumAFecha(tFecha *, int *, int *);

int main()
{
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, cant;
    tFecha f = {12,1,2008};

    if(esFechaValida(&f, diasMes)) {
        printf("Ingrese cantidad de dias a sumar: ");
        scanf("%d", &cant);

        sumAFecha(&f, diasMes, &cant);
    } else {
        printf("La fecha es invalida.");
    }
    return 0;
}

int esFechaValida(tFecha* f, int *diasMes) {
    return f->anio >= A_MIN && f->anio <= A_MAX &&
           f->mes >= 1 && f->mes <= 12 &&
           f->dia >= 1 &&
           (f->dia <= *(diasMes+f->mes-1) || (BISIESTO(f->anio) && f->mes == 2 && f->dia == 29));
}

void sumAFecha(tFecha *f, int *diasMes, int *cant) {
    f->dia += *cant;

    while(f->dia > *(diasMes+f->mes-1)){
        f->dia -= *(diasMes+f->mes-1);
        f->mes++;
        if (f->mes > 12){
            f->mes = 1;
            f->anio++;
        }
    }

    printf("La fecha es: %d/%d/%d", f->dia, f->mes, f->anio);

}

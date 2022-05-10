#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define A_MIN 1600
#define A_MAX 5000

typedef struct {
    int dia, mes, anio;
}tFecha;

int esFechaValida(tFecha *);
int esBisiesto(int *);
int esDiaValido(tFecha *);



#endif // FUNCTIONS_H_INCLUDED

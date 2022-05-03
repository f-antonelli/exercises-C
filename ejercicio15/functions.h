#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define A_MIN 1600
#define A_MAX 5000
#define BISIESTO(A) (A % 4 == 0 || (A % 100 == 0 && A % 400 != 0))

typedef struct {
    int dia, mes, anio;
} tFecha;

int esFechaValida(tFecha *, int *);
int esBisiesto(int *);
void diaSiguiente(tFecha *, int *);


#endif // FUNCTIONS_H_INCLUDED

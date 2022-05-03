#include "Fecha.h"

Fecha::Fecha()
{
    this->diaRel = 1;
    //ctor por defecto, si no le paso parametros
}

Fecha::Fecha(int d, int m, int a)
{
    //ctor
    if(!esFechaValida(d, m, a))
        return;

    cantAnios = a - ANIO_BASE;
    diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios /400;
    this->diaRel = diasAniosCompl + diaDelAnio(d, m, a);
}


Fecha Fecha::sumarDias(int dias) const; //no modifica al obj this
int Fecha::difDias(const Fecha *f2) const;
void Fecha::sumarDias(int dias);
void Fecha::getDMA(int *d, int *m, int *a) const;
void Fecha::setDMA(int d, int m, int a);

bool Fecha::esFechaValida(int d, int m, int a)
{
    return a >= ANIO_BASE && m >= 1 && m <= 12 && d >= 1 && d <= cantDiasMes(m, a);
}

int Fecha::cantDiasMes(int m, int a)
{
    static int cdm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(m == 2 && esBisiesto(a))
        return 29;

    return cmd[m-1];
}

int Fecha::diaDelAnio(int d, int m, int a)
{
}

// :: es el scope y sirva para definir a que clase pertenece

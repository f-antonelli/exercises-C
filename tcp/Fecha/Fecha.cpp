#include "Fecha.h"
#include "FechaInvalidaException.h"


const int Fecha::acumDiasIniMes[2][14] =
{
    { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
    { 0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
};

Fecha::Fecha()
{
    this->diaRel = 1;
    //ctor por defecto, si no le paso parametros
}

Fecha::Fecha(int d, int m, int a)
{
    //ctor
    this->setDMA(d, m, a);
}


//no modifica al obj this, devuelve otra fecha
Fecha Fecha::operator +(int dias) const
{
    if(this->diaRel + dias <= 0)
        throw FechaInvalidaException("La operacion + no se pudo realizar: Los dias dejan a la fecha invalida.");

    //hago copia del diaRel al objeto suma para poder modificarlo
    Fecha suma(*this);

    suma.diaRel += dias;

    return suma;
}

// trabaja sobre la misma fecha, la modifica
Fecha& Fecha::operator +=(int dias)
{
    if(this->diaRel + dias <= 0)
        throw FechaInvalidaException("La operacion += no se pudo realizar: Los dias dejan a la fecha invalida.");

    this->diaRel += dias;

    return *this;
}

int Fecha::operator -(const Fecha& f2) const
{
    return this->diaRel - f2.diaRel;
}

bool Fecha::esFechaValida(int d, int m, int a)
{
    return a >= ANIO_BASE && m >= 1 && m <= 12 && d >= 1 && d <= cantDiasMes(m, a);
}

int Fecha::cantDiasMes(int m, int a)
{
    static int cdm[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(m == 2 && esBisiesto(a))
        return 29;

    return cdm[m-1];
}

bool Fecha::esBisiesto(int a)
{
    return (a % 4 == 0 && a % 100 != 0) || a % 400 == 0;
}

int Fecha::diaDelAnio(int d, int m, int a)
{
    int fila = esBisiesto(a) ? 1 : 0;

    return acumDiasIniMes[fila][m] + d;
}
// :: es el scope y sirva para definir a que clase pertenece
void Fecha::getDMA(int& d, int& m, int& a) const
{
    int cantAnios = this->diaRel / 365;
    int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;;

    while(diasAniosCompl >= this->diaRel)
    {
        cantAnios--;
        diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
    }

    a = ANIO_BASE + cantAnios;
    int diaDelAnio = this->diaRel - diasAniosCompl;

    int fila = esBisiesto(a) ? 1 : 0;
    int mes = 2;

    while(diaDelAnio > acumDiasIniMes[fila][mes])
        mes++;

    mes--;
    m = mes;

    d = diaDelAnio - acumDiasIniMes[fila][mes];
}

void Fecha::setDMA(int d, int m, int a)
{
    if(!esFechaValida(d, m, a))
        throw FechaInvalidaException("La fecha es invalida.");

    int cantAnios = a - ANIO_BASE;
    int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
    this->diaRel = diasAniosCompl + diaDelAnio(d, m, a);
}

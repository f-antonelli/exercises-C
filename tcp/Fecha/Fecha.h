#ifndef FECHA_H
#define FECHA_H

#define ANIO_BASE 1601


class Fecha
{
private:
    int diaRel;

    static const int acumDiasIniMes[2][14];
    //static, no trabaja con this, puedo acceder desde el main
    static bool esFechaValida(int d, int m, int a);
    static int diaDelAnio(int d, int m, int a);
    static int cantDiasMes(int m, int a);
    static bool esBisiesto(int a);

public:
    Fecha(); //ctor default
    Fecha(int d, int m, int a); //ctor

    void setDMA(int d, int m, int a);
    //paso valor por referencia
    //porque usarlo? mas incomodo pasar por puntero por su sintaxis
    void getDMA(int& d, int& m, int& a) const;
    Fecha operator +(int dias) const; //no modifica al obj this
    Fecha operator -(int dias) const;
    Fecha& operator +=(int dias);
    Fecha& operator -=(int dias);
    Fecha operator ++();
    int operator -(const Fecha& f2) const;
    int diaSemana() const;
};

#endif // FECHA_H

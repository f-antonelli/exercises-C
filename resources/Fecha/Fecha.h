#ifndef FECHA_H
#define FECHA_H
#define ANIO_BASE 1601

class Fecha
{
private:
    int diaRel;

    //static, no trabaja con this, puedo acceder desde el main
    static bool esFechaValida(int d, int m, int a);
    static int diaDelAnio(int d, int m, int a);
    static int cantDiasMes(int m, int a);

public:
    Fecha(); //ctor default
    Fecha(int d, int m, int a); //ctor

    Fecha sumarDias(int dias) const; //no modifica al obj this
    void sumarDias(int dias);
    int difDias(const Fecha *f2) const;
    void getDMA(int *d, int *m, int *a) const;
    void setDMA(int d, int m, int a);
};

#endif // FECHA_H

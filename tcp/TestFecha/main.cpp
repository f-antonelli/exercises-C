#include <iostream>

#include "../Fecha/Fecha.h"
#include "../Fecha/FechaInvalidaException.h"

using namespace std;

#define TODO_OK 0
#define ERR_FECHA_INV 1

int main()
{
    int d, m, a;
    char c;

    cout << "Ingrese una fecha (D/M/A): ";
    cin >> d >> c >> m >> c >> a;

    try
    {
        Fecha hoy(d, m, a);

        hoy.getDMA(d, m, a);

        cout << "Esta es mi fecha" << endl;
        cout << d << '/' << m << '/' << a << endl;

        int dias = 20;

        hoy += dias;
        hoy.getDMA(d, m, a);

        cout << "Sumar " << dias << " dias a mi fecha (operator +=): ";
        cout << d << '/' << m << '/' << a << endl;

        Fecha suma = hoy + dias;
        suma.getDMA(d, m, a);

        cout << "Sumar " << dias << " dias a mi fecha (operator +): ";
        cout << d << '/' << m << '/' << a << endl;

        int dif = suma - hoy;

        cout << "La diferencia entre suma y hoy es: " << dif << endl;
    }
    catch(FechaInvalidaException ex)
    {
        cout << ex.getMensaje() << endl;
        return ERR_FECHA_INV;
    }

    return TODO_OK;
}

#include <iostream>

using namespace std;

int main()
{
    int num ;

    cout << "Ingrese numero: ";
    cin >> num;

    cout << "mi numero es: " << num << endl;

    Fecha hoy(4, 9, 2021);

    Fecha mas30 = hoy.sumarDias(30);

    bool valida = Fecha::esFechaValida(4, 9, 2021);

    return 0;
}

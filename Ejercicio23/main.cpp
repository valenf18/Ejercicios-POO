#include <iostream>
#include "CuentaBancaria.h"

int main() {
    CuentaBancaria cuenta1(1000);
    CuentaBancaria cuenta2(800);

    cuenta1.depositar(200);
    cuenta2.depositar(100);

    cout << "Cuenta 1: ";
    cuenta1.mostrar();

    cout << "Cuenta 2: ";
    cuenta2.mostrar();

    if (compararSaldo(cuenta1, cuenta2))
        cout << "La Cuenta 1 tiene mayor saldo que la Cuenta 2." << endl;
    else
        cout << "La Cuenta 1 tiene saldo igual o menor que la Cuenta 2." << endl;

    return 0;
}

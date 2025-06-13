#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    int saldo;

public:
    CuentaBancaria(int saldoInicial) : saldo(saldoInicial) {}

    void depositar(int monto) {
        saldo += monto;
    }

    void mostrar() const {
        cout << "Saldo actual: $" << saldo << endl;
    }

    // Función amiga
    friend bool compararSaldo(const CuentaBancaria& c1, const CuentaBancaria& c2);
};

#endif // CUENTABANCARIA_H

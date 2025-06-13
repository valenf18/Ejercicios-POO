#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>

class Sensor {
public:
    int valorActual;

    Sensor() {
        valorActual = rand() % 1024; // Valor entre 0 y 1023
    }

    // Inline implícito (dentro de clase)
    int getValorBruto() const {
        return valorActual;
    }

    // Inline explícito
    inline double getValorNormalizado() const {
        return valorActual / 1023.0;
    }

    // Offline (declaración)
    int getValorBrutoOffline() const;
    double getValorNormalizadoOffline() const;
};

#endif // SENSOR_H

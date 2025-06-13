#include "sensor.h"

// Definición fuera de clase, sin inline
int Sensor::getValorBrutoOffline() const {
    return valorActual;
}

double Sensor::getValorNormalizadoOffline() const {
    return valorActual / 1023.0;
}

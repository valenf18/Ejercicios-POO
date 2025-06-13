#ifndef CAJAMEDICAMENTO_H
#define CAJAMEDICAMENTO_H

#include <QString>

class CajaMedicamento {
private:
    int id;
    float dosisTotales;

public:
    // Constructor para crear caja nueva (sin ID)
    CajaMedicamento(float dosis);

    // Constructor para cargar desde base de datos (con ID)
    CajaMedicamento(int id, float dosis);

    CajaMedicamento operator+(const CajaMedicamento& otra) const;
    bool operator==(const CajaMedicamento& otra) const;
    QString toString() const;

    int getId() const;
    float getDosisTotales() const;
};

#endif // CAJAMEDICAMENTO_H

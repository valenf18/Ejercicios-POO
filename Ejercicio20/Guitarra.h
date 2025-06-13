#ifndef GUITARRA_H
#define GUITARRA_H

#include "Instrumento.h"

class Guitarra : public Instrumento {
    int cuerdas;

public:
    Guitarra() : cuerdas(6) {}
    void sonar() const override {
        cout << "Guitarra suena..." << endl;
    }

    void setCuerdas(int c) { cuerdas = c; }
    int getCuerdas() const { return cuerdas; }
};

#endif // GUITARRA_H

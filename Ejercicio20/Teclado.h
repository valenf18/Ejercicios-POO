#ifndef TECLADO_H
#define TECLADO_H

#include "Instrumento.h"
#include "Electrico.h"

class Teclado : public Instrumento, public Electrico {
    int teclas;

public:
    Teclado() : teclas(61) {}
    ~Teclado() override = default;

    void sonar() const override {
        cout << "Teclado suena..." << endl;
    }

    void setTeclas(int t) { teclas = t; }
    int getTeclas() const { return teclas; }
};

#endif // TECLADO_H

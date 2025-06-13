#ifndef BATERIA_H
#define BATERIA_H

#include "Instrumento.h"

class Bateria : public Instrumento {
    int tambores;

public:
    Bateria() : tambores(5) {}
    void sonar() const override {
        cout << "Batería suena..." << endl;
    }

    void setTambores(int t) { tambores = t; }
    int getTambores() const { return tambores; }
};

#endif // BATERIA_H

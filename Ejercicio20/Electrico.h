#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <iostream>
using namespace std;

class Electrico {
protected:
    int voltaje;

public:
    Electrico() : voltaje(220) {}
    virtual ~Electrico() {
        cout << "Desenchufado" << endl;
    }

    int getVoltaje() const { return voltaje; }
    void setVoltaje(int v) { voltaje = v; }
};

#endif // ELECTRICO_H

#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <iostream>
#include <string>
using namespace std;

class Instrumento {
protected:
    string marca;

public:
    Instrumento() : marca("Yamaha") {}
    virtual ~Instrumento() = default;

    virtual void sonar() const = 0;
    virtual void verlo() const {
        cout << "Marca: " << marca << endl;
    }

    void setMarca(const string& m) { marca = m; }
    string getMarca() const { return marca; }
};

#endif // INSTRUMENTO_H

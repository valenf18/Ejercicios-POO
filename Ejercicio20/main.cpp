#include <iostream>
#include <vector>
#include "Guitarra.h"
#include "Bateria.h"
#include "Teclado.h"

using namespace std;

int main() {
    vector<Instrumento*> instrumentos;

    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Teclado());
    instrumentos.push_back(new Teclado());
    instrumentos.push_back(new Guitarra());

    cout << "----- Ver Marcas -----" << endl;
    for (auto inst : instrumentos) {
        inst->verlo();
    }

    cout << "----- Sonar -----" << endl;
    for (auto inst : instrumentos) {
        inst->sonar();
    }

    cout << "----- Liberando Memoria -----" << endl;
    for (auto inst : instrumentos) {
        delete inst;
    }

    return 0;
}

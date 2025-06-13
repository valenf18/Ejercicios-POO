/* Ejercicio 2:
 * Crear un std::vector para contener objetos de la clase std::string
 * Cargar 5 expresiones idiomáticas, como por ejemplo: pan comido
 * Publicar por consola ordenado alfabéticamente sin considerar los espacios*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> expresiones = {
        "pan comido",
        "tirar la toalla",
        "costar un ojo de la cara",
        "ponerse las pilas",
        "estar en las nubes"
    };

    vector<string> expresionesSinEspacios;

    for (const string& expresion : expresiones) {
        string sinEspacios;
        for (char c : expresion) {
            if (c != ' ') {
                sinEspacios += c;
            }
        }
        expresionesSinEspacios.push_back(sinEspacios);
    }

    sort(expresionesSinEspacios.begin(), expresionesSinEspacios.end());

    cout << "Expresiones idiomaticas ordenadas alfabeticamente sin espacios:" << endl;
    for (const string& expresion : expresionesSinEspacios) {
        cout << expresion << endl;
    }

    return 0;
}

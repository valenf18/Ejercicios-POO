/* Ejercicio 1:
 * Definir una clase Poste con dos atributos: altura (int, en metros) y diametro (float, en cm).
 * Crear un vector para almacenar varios objetos de la clase Poste.
 * Cargar al menos 5 postes con diferentes alturas y diámetros.
 * Ordenar los postes de menor a mayor según su altura.
 * Mostrar en consola la lista de postes antes y después ordenarlos.
 * Resolver únicamente con las clases, funciones y estructuras vistas hasta el momento en la asignatura y en asignaturas anteriores.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Poste {
public:
    int altura;      // Altura en metros
    float diametro;  // Diametro en centimetros

    Poste(int a, float d) : altura(a), diametro(d) {}

    void mostrar() const {
        cout << "Altura: " << altura << " m, Diametro: " << diametro << " cm" << endl;
    }
};

int main() {
    vector<Poste> postes;

    postes.push_back(Poste(12, 15.5));
    postes.push_back(Poste(8, 10.2));
    postes.push_back(Poste(5, 12.8));
    postes.push_back(Poste(10, 18.4));
    postes.push_back(Poste(15, 20.1));

    cout << "Lista de postes antes de ordenar:" << endl;
    for (const Poste& poste : postes) {
        poste.mostrar();
    }

    sort(postes.begin(), postes.end(), [](const Poste& a, const Poste& b) {
        return a.altura < b.altura;
    });

    cout << "\nLista de postes despues de ordenar:" << endl;
    for (const Poste& poste : postes) {
        poste.mostrar();
    }

    return 0;
}




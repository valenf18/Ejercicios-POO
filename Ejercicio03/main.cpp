#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Libro {
public:
    int numPaginas;       // Numero de paginas
    string titulo;        // Titulo del libro

    // Constructor
    Libro(int paginas, string nombre) : numPaginas(paginas), titulo(nombre) {}

    // Metodo para mostrar informacion del libro
    void mostrar() const {
        cout << "Titulo: " << titulo << ", Paginas: " << numPaginas << endl;
    }
};

int main() {
    vector<Libro> biblioteca; // Vector para almacenar los libros
    const int limiteMemoria = 200 * 1024 * 1024; // Limite en bytes
    int memoriaUsada = 0;
    int numObjetos = 0;

    // Lista de nombres para los libros
    string nombresLibros[] = {
        "El Alquimista", "1984", "Cien Anios de Soledad",
        "El Principito", "Don Quijote", "Rayuela",
        "Ficciones", "La Metamorfosis", "Matar a un Ruisenior", "La Divina Comedia"
    };
    int totalNombres = sizeof(nombresLibros) / sizeof(nombresLibros[0]);

    while (memoriaUsada < limiteMemoria) {
        // Crear un nuevo libro
        string titulo = nombresLibros[numObjetos % totalNombres];
        int paginas = 100 + (numObjetos % 400); // Numero arbitrario de paginas
        biblioteca.push_back(Libro(paginas, titulo));

        // Calcular la memoria utilizada
        memoriaUsada += sizeof(Libro);
        memoriaUsada += titulo.size(); // Aproximar el tamaño del string
        numObjetos++;
    }

    // Mostrar la lista de los primeros libros cargados
    cout << "Lista de los 5 primeros libros:" << endl;
    for (size_t i = 0; i < 5 && i < biblioteca.size(); i++) {
        biblioteca[i].mostrar();
    }

    // Mostrar resultados finales
    cout << "Memoria alcanzada: " << memoriaUsada / (1024.0 * 1024.0) << " MB" << endl;
    cout << "Numero de objetos creados: " << numObjetos << endl;

    return 0;
}

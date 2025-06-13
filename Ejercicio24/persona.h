#ifndef PERSONA_H
#define PERSONA_H

#include <QString>
#include <QDebug>

class Persona {
private:
    QString nombre;
    static int contador;  // Atributo estático

public:
    Persona(const QString &nombre) : nombre(nombre) {
        contador++;
    }

    void mostrar() const {
        qDebug() << "Nombre:" << nombre;
    }

    static int totalPersonas() {
        return contador;
    }
};

#endif // PERSONA_H

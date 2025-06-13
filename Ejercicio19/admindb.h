#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QList>
#include "cajamedicamento.h"

class AdminDB {
public:
    static AdminDB* getInstancia();
    void conectar();
    bool insertarCaja(float dosis);
    QList<CajaMedicamento> obtenerTodas();
    float obtenerTotalDosis();

private:
    AdminDB();
    static AdminDB* instancia;
    QSqlDatabase db;
};

#endif // ADMINDB_H

#include "admindb.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

AdminDB* AdminDB::instancia = nullptr;

AdminDB::AdminDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("medicamentos.db");
}

AdminDB* AdminDB::getInstancia() {
    if (instancia == nullptr) {
        instancia = new AdminDB();
    }
    return instancia;
}

void AdminDB::conectar() {
    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos: " << db.lastError().text();
    } else {
        qDebug() << "Conectado a la base de datos";
        QSqlQuery query;
        // Crear tabla si no existe
        if (!query.exec("CREATE TABLE IF NOT EXISTS cajas_medicamentos ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                        "dosis_totales REAL)")) {
            qDebug() << "Error al crear la tabla: " << query.lastError().text();
        }
    }
}

bool AdminDB::insertarCaja(float dosis) {
    float totalDosis = obtenerTotalDosis();
    qDebug() << "Total dosis en la base de datos antes de la inserción:" << totalDosis;
    qDebug() << "Intentando insertar caja con dosis:" << dosis;

    if (totalDosis + dosis > 1000.0f) {
        qDebug() << "No se puede agregar la caja: excede las 1000 dosis.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO cajas_medicamentos (dosis_totales) VALUES (:dosis)");
    query.bindValue(":dosis", dosis);

    if (!query.exec()) {
        qDebug() << "Error al insertar la caja:" << query.lastError().text();
        return false;
    }

    qDebug() << "Caja insertada correctamente.";
    return true;
}

QList<CajaMedicamento> AdminDB::obtenerTodas() {
    QList<CajaMedicamento> cajas;
    QSqlQuery query("SELECT * FROM cajas_medicamentos");

    while (query.next()) {
        int id = query.value("id").toInt();
        float dosis = query.value("dosis_totales").toFloat();
        cajas.append(CajaMedicamento(id, dosis));
    }

    return cajas;
}

float AdminDB::obtenerTotalDosis() {
    float total = 0.0f;
    QSqlQuery query("SELECT SUM(dosis_totales) FROM cajas_medicamentos");

    if (query.next()) {
        QVariant value = query.value(0);
        if (!value.isNull()) {
            total = value.toFloat();
        }
    }

    qDebug() << "Total dosis calculadas en la base de datos:" << total;
    return total;
}

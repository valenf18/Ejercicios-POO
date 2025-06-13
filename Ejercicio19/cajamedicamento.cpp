#include "cajamedicamento.h"

CajaMedicamento::CajaMedicamento(float dosis)
    : id(-1), dosisTotales(dosis) {}

CajaMedicamento::CajaMedicamento(int id, float dosis)
    : id(id), dosisTotales(dosis) {}

CajaMedicamento CajaMedicamento::operator+(const CajaMedicamento& otra) const {
    return CajaMedicamento(this->dosisTotales + otra.dosisTotales);
}

bool CajaMedicamento::operator==(const CajaMedicamento& otra) const {
    return this->dosisTotales == otra.dosisTotales;
}

QString CajaMedicamento::toString() const {
    return QString("Caja ID %1 - Dosis: %2").arg(id).arg(dosisTotales);
}

int CajaMedicamento::getId() const {
    return id;
}

float CajaMedicamento::getDosisTotales() const {
    return dosisTotales;
}

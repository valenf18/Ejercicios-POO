#include "userwindow.h"
#include <QLabel>
#include <QVBoxLayout>

UserWindow::UserWindow(const QString &nombre, const QString &ultimoIngreso, QWidget *parent)
    : QWidget(parent) {

    setWindowTitle("Bienvenido");

    nombreLabel = new QLabel(nombre);
    ingresoLabel = new QLabel("Último ingreso: " + ultimoIngreso);

    nombreLabel->setStyleSheet("font-size: 24pt; font-weight: bold;");
    ingresoLabel->setStyleSheet("font-size: 12pt; color: gray;");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(nombreLabel, 0, Qt::AlignCenter);
    layout->addWidget(ingresoLabel, 0, Qt::AlignCenter);
    setLayout(layout);
}

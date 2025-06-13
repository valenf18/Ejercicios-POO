#include "formwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

FormWindow::FormWindow(QWidget *parent)
    : QWidget(parent) {

    setWindowTitle("Formulario");

    QLabel *legajoLabel = new QLabel("Legajo:");
    QLabel *nombreLabel = new QLabel("Nombre:");
    QLabel *apellidoLabel = new QLabel("Apellido:");

    legajoEdit = new QLineEdit;
    nombreEdit = new QLineEdit;
    apellidoEdit = new QLineEdit;
    botonGuardar = new QPushButton("Guardar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(legajoLabel, 0, 0);
    layout->addWidget(legajoEdit, 0, 1);
    layout->addWidget(nombreLabel, 1, 0);
    layout->addWidget(nombreEdit, 1, 1);
    layout->addWidget(apellidoLabel, 2, 0);
    layout->addWidget(apellidoEdit, 2, 1);
    layout->addWidget(botonGuardar, 3, 1);

    setLayout(layout);
    resize(400, 150);
}

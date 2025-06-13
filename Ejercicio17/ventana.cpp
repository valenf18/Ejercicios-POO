#include "ventana.h"
#include "ui_ventana.h"
#include "boton.h"
#include <QDebug>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent), ui(new Ui::Ventana) {
    ui->setupUi(this);

    Boton *b1 = static_cast<Boton*>(ui->boton1);
    Boton *b2 = static_cast<Boton*>(ui->boton2);
    Boton *b3 = static_cast<Boton*>(ui->boton3);
    Boton *b4 = static_cast<Boton*>(ui->boton4);
    Boton *b5 = static_cast<Boton*>(ui->boton5);

    b1->colorear(Boton::Rojo);
    b1->setTexto("Mi dentista");

    b2->colorear(Boton::Violeta);
    b2->setTexto("Visitas");

    b3->colorear(Boton::VerdeClaro);
    b3->setTexto("Técnicas de higiene");

    b4->colorear(Boton::Celeste);
    b4->setTexto("Mi boca");

    b5->colorear(Boton::VerdeAgua);
    b5->setTexto("Hora de cepillarse");

    connect(b1, &Boton::signal_clic, this, [](){ qDebug() << "Mi dentista"; });
    connect(b2, &Boton::signal_clic, this, [](){ qDebug() << "Visitas"; });
    connect(b3, &Boton::signal_clic, this, [](){ qDebug() << "Técnicas de higiene"; });
    connect(b4, &Boton::signal_clic, this, [](){ qDebug() << "Mi boca"; });
    connect(b5, &Boton::signal_clic, this, [](){ qDebug() << "Hora de cepillarse"; });
}

Ventana::~Ventana() {
    delete ui;
}

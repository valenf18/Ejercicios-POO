#include "formwindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QApplication>

FormWindow::FormWindow(QWidget *parent)
    : QWidget(parent) {

    setWindowTitle("Formulario");

    QLabel *legajoLabel = new QLabel("Legajo:");
    QLabel *nombreLabel = new QLabel("Nombre:");
    QLabel *apellidoLabel = new QLabel("Apellido:");
    QLabel *captchaTextoLabel = new QLabel("Captcha:");
    captchaLabel = new QLabel;
    captchaIngresadoEdit = new QLineEdit;

    generarCaptcha(); // Genera y muestra un captcha aleatorio

    legajoEdit = new QLineEdit;
    nombreEdit = new QLineEdit;
    apellidoEdit = new QLineEdit;
    botonAlta = new QPushButton("Alta");

    connect(botonAlta, &QPushButton::clicked, this, &FormWindow::validarFormulario);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(legajoLabel, 0, 0);
    layout->addWidget(legajoEdit, 0, 1);
    layout->addWidget(nombreLabel, 1, 0);
    layout->addWidget(nombreEdit, 1, 1);
    layout->addWidget(apellidoLabel, 2, 0);
    layout->addWidget(apellidoEdit, 2, 1);
    layout->addWidget(captchaTextoLabel, 3, 0);
    layout->addWidget(captchaLabel, 3, 1);
    layout->addWidget(captchaIngresadoEdit, 4, 1);
    layout->addWidget(botonAlta, 5, 1);

    setLayout(layout);
    resize(400, 200);
}

void FormWindow::generarCaptcha() {
    int captcha = QRandomGenerator::global()->bounded(1000, 9999);
    captchaGenerado = QString::number(captcha);
    captchaLabel->setText(captchaGenerado);
}

void FormWindow::validarFormulario() {
    bool todoOk = true;

    // Validaciones
    int legajo = legajoEdit->text().toInt();
    if (legajo < 1 || legajo > 10000) {
        legajoEdit->setStyleSheet("border: 2px solid red");
        todoOk = false;
    } else {
        legajoEdit->setStyleSheet("");
    }

    if (nombreEdit->text().trimmed().isEmpty()) {
        nombreEdit->setStyleSheet("border: 2px solid red");
        todoOk = false;
    } else {
        nombreEdit->setStyleSheet("");
    }

    if (apellidoEdit->text().trimmed().isEmpty()) {
        apellidoEdit->setStyleSheet("border: 2px solid red");
        todoOk = false;
    } else {
        apellidoEdit->setStyleSheet("");
    }

    if (captchaIngresadoEdit->text() != captchaGenerado) {
        captchaIngresadoEdit->setStyleSheet("border: 2px solid red");
        todoOk = false;
    } else {
        captchaIngresadoEdit->setStyleSheet("");
    }

    if (todoOk) {
        QApplication::quit();
    }
}

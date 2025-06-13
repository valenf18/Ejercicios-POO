#include "loginwindow.h"
#include "formwindow.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QKeyEvent>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent) {

    setWindowTitle("Login");

    QLabel *usuarioLabel = new QLabel("Usuario:");
    QLabel *claveLabel = new QLabel("Clave:");

    usuarioEdit = new QLineEdit;
    claveEdit = new QLineEdit;
    claveEdit->setEchoMode(QLineEdit::Password); // Asteriscos

    botonIngresar = new QPushButton("Ingresar");

    // Enter activa el botón
    connect(usuarioEdit, &QLineEdit::returnPressed, botonIngresar, &QPushButton::click);
    connect(claveEdit, &QLineEdit::returnPressed, botonIngresar, &QPushButton::click);
    connect(botonIngresar, &QPushButton::clicked, this, &LoginWindow::validarCredenciales);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(usuarioLabel, 0, 0);
    layout->addWidget(usuarioEdit, 0, 1);
    layout->addWidget(claveLabel, 1, 0);
    layout->addWidget(claveEdit, 1, 1);
    layout->addWidget(botonIngresar, 2, 1);

    setLayout(layout);
    resize(300, 100);
}

void LoginWindow::validarCredenciales() {
    QString usuario = usuarioEdit->text().trimmed();
    QString clave = claveEdit->text();

    if (usuario == "admin" && clave == "1111") {
        FormWindow *formulario = new FormWindow;
        formulario->show();
        this->close();
    } else {
        claveEdit->clear();
    }
}

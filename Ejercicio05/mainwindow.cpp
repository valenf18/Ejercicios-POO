#include "mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QVBoxLayout>
#include <QDebug>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {

    imagenLabel = new QLabel(this);
    imagenLabel->setAlignment(Qt::AlignCenter);

    QPixmap imagen("C:/Users/Valen/Pictures/Porsche/porscherosa"); // ⚠️ Cambiá esta ruta por una válida
    if (!imagen.isNull()) {
        imagenLabel->setPixmap(imagen.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "No se pudo cargar la imagen.";
    }

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(imagenLabel);
    setLayout(layout);

    // Timer para cerrar la app después de 3 segundos
    temporizador = new QTimer(this);
    temporizador->setSingleShot(true);
    connect(temporizador, &QTimer::timeout, this, &MainWindow::cerrarAplicacion);
    temporizador->start(3000); // 3 segundos
}

void MainWindow::cerrarAplicacion() {
    close(); // Cierra la ventana
    qApp->quit(); // Termina la aplicación
}

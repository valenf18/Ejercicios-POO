#include "mainwindow.h"
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {

    setWindowTitle("Volumen");
    resize(300, 50);

    slider = new QSlider(Qt::Horizontal);
    spinBox = new QSpinBox;

    slider->setRange(0, 100);
    spinBox->setRange(0, 100);
    spinBox->setValue(15);

    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(actualizarTitulo(int)));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    setLayout(layout);
}

void MainWindow::actualizarTitulo(int valor) {
    setWindowTitle(QString("Volumen: %1").arg(valor));
}

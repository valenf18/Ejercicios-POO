#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent) {
    spinDosis = new QDoubleSpinBox;
    spinDosis->setRange(0.1, 1000.0);
    spinDosis->setDecimals(1);
    spinDosis->setSingleStep(0.5);

    btnAgregar = new QPushButton("Agregar");
    btnSumar = new QPushButton("Sumar");
    btnComparar = new QPushButton("Comparar");
    lista = new QListWidget;
    lista->setSelectionMode(QAbstractItemView::MultiSelection);  // Permitir selección múltiple

    QHBoxLayout* inputLayout = new QHBoxLayout;
    inputLayout->addWidget(spinDosis);
    inputLayout->addWidget(btnAgregar);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(btnSumar);
    buttonsLayout->addWidget(btnComparar);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(lista);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
    setWindowTitle("Gestión de Medicamentos");

    AdminDB::getInstancia()->conectar();
    cargarCajas();

    connect(btnAgregar, SIGNAL(clicked()), this, SLOT(agregarCaja()));
    connect(btnSumar, SIGNAL(clicked()), this, SLOT(sumarCajas()));
    connect(btnComparar, SIGNAL(clicked()), this, SLOT(compararCajas()));
}

void MainWindow::cargarCajas() {
    lista->clear();
    QList<CajaMedicamento> cajas = AdminDB::getInstancia()->obtenerTodas();
    for (const CajaMedicamento& caja : cajas) {
        QListWidgetItem* item = new QListWidgetItem(caja.toString());
        item->setData(Qt::UserRole, QVariant::fromValue(caja.getId()));
        item->setData(Qt::UserRole + 1, caja.getDosisTotales());
        lista->addItem(item);
    }
}

void MainWindow::agregarCaja() {
    float dosis = spinDosis->value();
    if (!AdminDB::getInstancia()->insertarCaja(dosis)) {
        QMessageBox::warning(this, "Error", "No se puede agregar la caja: excede las 1000 dosis.");
        return;
    }
    cargarCajas();
}

void MainWindow::sumarCajas() {
    QList<QListWidgetItem*> seleccionados = lista->selectedItems();
    if (seleccionados.size() != 2) {
        QMessageBox::warning(this, "Error", "Seleccioná exactamente dos cajas.");
        return;
    }

    float dosis1 = seleccionados[0]->data(Qt::UserRole + 1).toFloat();
    float dosis2 = seleccionados[1]->data(Qt::UserRole + 1).toFloat();
    CajaMedicamento c1(dosis1), c2(dosis2);
    CajaMedicamento suma = c1 + c2;

    if (!AdminDB::getInstancia()->insertarCaja(suma.getDosisTotales())) {
        QMessageBox::warning(this, "Error", "No se puede sumar: excede las 1000 dosis.");
        return;
    }

    cargarCajas();
}

void MainWindow::compararCajas() {
    QList<QListWidgetItem*> seleccionados = lista->selectedItems();
    if (seleccionados.size() != 2) {
        QMessageBox::warning(this, "Error", "Seleccioná exactamente dos cajas.");
        return;
    }

    float dosis1 = seleccionados[0]->data(Qt::UserRole + 1).toFloat();
    float dosis2 = seleccionados[1]->data(Qt::UserRole + 1).toFloat();
    CajaMedicamento c1(dosis1), c2(dosis2);

    if (c1 == c2)
        qDebug() << "Las cajas tienen la misma cantidad de dosis.";
    else
        qDebug() << "Las cajas NO tienen la misma cantidad de dosis.";
}

MainWindow::~MainWindow() {
    // Liberar recursos dinámicos
    delete spinDosis;
    delete btnAgregar;
    delete btnSumar;
    delete btnComparar;
    delete lista;
}

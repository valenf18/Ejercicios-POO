#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include "admindb.h"
#include "cajamedicamento.h"

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void agregarCaja();
    void sumarCajas();
    void compararCajas();

private:
    void cargarCajas();

    QDoubleSpinBox *spinDosis;
    QPushButton *btnAgregar;
    QPushButton *btnSumar;
    QPushButton *btnComparar;
    QListWidget *lista;
};

#endif // MAINWINDOW_H

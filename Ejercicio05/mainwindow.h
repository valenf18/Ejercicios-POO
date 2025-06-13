#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;
class QTimer;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void cerrarAplicacion();

private:
    QLabel* imagenLabel;
    QTimer* temporizador;
};

#endif // MAINWINDOW_H

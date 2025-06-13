#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QSlider;
class QSpinBox;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void actualizarTitulo(int valor);

private:
    QSlider* slider;
    QSpinBox* spinBox;
};

#endif // MAINWINDOW_H

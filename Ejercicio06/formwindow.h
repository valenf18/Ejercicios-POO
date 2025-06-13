#ifndef FORMWINDOW_H
#define FORMWINDOW_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QPushButton;

class FormWindow : public QWidget {
    Q_OBJECT

public:
    explicit FormWindow(QWidget *parent = nullptr);

private:
    QLineEdit *legajoEdit;
    QLineEdit *nombreEdit;
    QLineEdit *apellidoEdit;
    QPushButton *botonGuardar;
};

#endif // FORMWINDOW_H

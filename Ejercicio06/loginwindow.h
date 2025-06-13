#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void validarCredenciales();

private:
    QLineEdit *usuarioEdit;
    QLineEdit *claveEdit;
    QPushButton *botonIngresar;
};

#endif // LOGINWINDOW_H

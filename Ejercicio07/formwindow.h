#ifndef FORMWINDOW_H
#define FORMWINDOW_H

#include <QWidget>

class QLineEdit;
class QPushButton;
class QLabel;

class FormWindow : public QWidget {
    Q_OBJECT

public:
    explicit FormWindow(QWidget *parent = nullptr);

private slots:
    void validarFormulario();

private:
    QLineEdit *legajoEdit;
    QLineEdit *nombreEdit;
    QLineEdit *apellidoEdit;
    QLineEdit *captchaIngresadoEdit;
    QLabel *captchaLabel;
    QPushButton *botonAlta;

    QString captchaGenerado;
    void generarCaptcha();
};

#endif // FORMWINDOW_H

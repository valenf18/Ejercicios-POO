#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>

class QLabel;

class UserWindow : public QWidget {
    Q_OBJECT

public:
    explicit UserWindow(const QString &nombre, const QString &ultimoIngreso, QWidget *parent = nullptr);

private:
    QLabel *nombreLabel;
    QLabel *ingresoLabel;
};

#endif // USERWINDOW_H

#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class QLabel;

class VentanaPrincipal : public QWidget {
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = nullptr);

private slots:
    void imagenDescargada(QNetworkReply *reply);

private:
    QLabel* imagenLabel;
    QNetworkAccessManager* manager;
};

#endif // VENTANAPRINCIPAL_H

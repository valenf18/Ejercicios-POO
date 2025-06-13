#include "ventanaprincipal.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QPixmap>
#include <QNetworkRequest>

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QWidget(parent) {

    setWindowTitle("Ventana Fullscreen");

    imagenLabel = new QLabel(this);
    imagenLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(imagenLabel);
    setLayout(layout);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &VentanaPrincipal::imagenDescargada);

    QUrl url("https://picsum.photos/1600/900"); // Imagen fullscreen
    QNetworkRequest request(url);
    manager->get(request);
}

void VentanaPrincipal::imagenDescargada(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QPixmap imagen;
        imagen.loadFromData(reply->readAll());
        imagenLabel->setPixmap(imagen.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    reply->deleteLater();
}

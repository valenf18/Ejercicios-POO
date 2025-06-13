#include "loginwindow.h"
#include "ventanaprincipal.h"

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QNetworkRequest>
#include <QMessageBox>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent) {

    setFixedSize(500, 300);
    setWindowTitle("Login con fondo remoto");

    fondoLabel = new QLabel(this);
    fondoLabel->setScaledContents(true);
    fondoLabel->lower();

    usuarioEdit = new QLineEdit;
    claveEdit = new QLineEdit;
    claveEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Ingresar");

    QVBoxLayout *formLayout = new QVBoxLayout;
    formLayout->addWidget(usuarioEdit);
    formLayout->addWidget(claveEdit);
    formLayout->addWidget(loginButton);

    QWidget* formWidget = new QWidget;
    formWidget->setLayout(formLayout);
    formWidget->setStyleSheet("background: rgba(255, 255, 255, 180); padding: 10px;");

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(formWidget, 0, Qt::AlignCenter);
    setLayout(mainLayout);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &LoginWindow::onImageDownloaded);

    descargarImagenFondo();
}

void LoginWindow::descargarImagenFondo() {
    QUrl url("https://picsum.photos/800/600"); // Imagen temporal
    QNetworkRequest request(url);
    manager->get(request);
}

void LoginWindow::onImageDownloaded(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        fondoPixmap.loadFromData(reply->readAll());
        fondoLabel->setPixmap(fondoPixmap.scaled(size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
        fondoLabel->resize(size());
        imagenCargada = true;
    } else {
        qDebug() << "Error al descargar imagen: " << reply->errorString();
    }
    reply->deleteLater();
}

void LoginWindow::onLoginClicked() {
    if (!imagenCargada) {
        QMessageBox::warning(this, "Espera", "Esperando que se cargue la imagen de fondo...");
        return;
    }

    if (usuarioEdit->text() == "admin" && claveEdit->text() == "1234") {
        VentanaPrincipal* v = new VentanaPrincipal;
        this->close();
        v->showFullScreen();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos");
    }
}

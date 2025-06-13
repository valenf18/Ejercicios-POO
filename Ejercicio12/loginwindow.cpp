#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"

#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWindow) {
    ui->setupUi(this);

    ui->claveLineEdit->setEchoMode(QLineEdit::Password);
    connect(ui->loginButton, &QPushButton::clicked, this, &LoginWindow::on_loginButton_clicked);

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &LoginWindow::respuestaApi);

    obtenerTemperatura();
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_loginButton_clicked() {
    QString usuario = ui->usuarioLineEdit->text().trimmed();
    QString clave = ui->claveLineEdit->text();

    if (usuario == "admin" && clave == "1234") {
        MainWindow *ventana = new MainWindow;
        ventana->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos");
    }
}

void LoginWindow::obtenerTemperatura() {
    // Usamos Open-Meteo API sin necesidad de clave
    QUrl url("https://api.open-meteo.com/v1/forecast?latitude=-31.4167&longitude=-64.1833&current_weather=true");
    QNetworkRequest request(url);
    networkManager->get(request);
}

void LoginWindow::respuestaApi(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
        if (jsonDoc.isObject()) {
            QJsonObject obj = jsonDoc.object();
            if (obj.contains("current_weather")) {
                QJsonObject clima = obj["current_weather"].toObject();
                double temp = clima["temperature"].toDouble();
                ui->temperaturaLabel->setText("Temp en Córdoba: " + QString::number(temp) + " °C");
            }
        }
    } else {
        ui->temperaturaLabel->setText("Error al obtener temperatura");
    }
    reply->deleteLater();
}

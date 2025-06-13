#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "userwindow.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWindow) {
    ui->setupUi(this);

    if (conectarBase()) {
        inicializarBase();
    }
}

LoginWindow::~LoginWindow() {
    delete ui;
}

bool LoginWindow::conectarBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usuarios.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Error", "No se pudo abrir la base de datos");
        return false;
    }
    return true;
}

void LoginWindow::inicializarBase() {
    QSqlQuery crear;
    crear.exec("CREATE TABLE IF NOT EXISTS usuarios ("
               "usuario TEXT PRIMARY KEY, "
               "clave TEXT, "
               "nombre TEXT, "
               "ultimo_ingreso TEXT)");

    QSqlQuery verificar;
    verificar.prepare("SELECT COUNT(*) FROM usuarios WHERE usuario = 'admin'");
    verificar.exec();
    if (verificar.next() && verificar.value(0).toInt() == 0) {
        QSqlQuery insertar;
        insertar.prepare("INSERT INTO usuarios (usuario, clave, nombre, ultimo_ingreso) "
                         "VALUES ('admin', '1234', 'Administrador', 'Nunca')");
        insertar.exec();
    }
}

void LoginWindow::on_loginButton_clicked() {
    QString usuario = ui->usuarioLineEdit->text().trimmed();
    QString clave   = ui->claveLineEdit->text();

    QSqlQuery query;
    query.prepare("SELECT nombre, ultimo_ingreso FROM usuarios WHERE usuario = ? AND clave = ?");
    query.addBindValue(usuario);
    query.addBindValue(clave);

    if (query.exec() && query.next()) {
        QString nombre = query.value(0).toString();
        QString ultimoIngreso = query.value(1).toString();

        QString fechaHora = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        QSqlQuery actualizar;
        actualizar.prepare("UPDATE usuarios SET ultimo_ingreso = ? WHERE usuario = ?");
        actualizar.addBindValue(fechaHora);
        actualizar.addBindValue(usuario);
        actualizar.exec();


        UserWindow *ventana = new UserWindow(nombre, ultimoIngreso);
        ventana->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o clave incorrectos");
    }
}

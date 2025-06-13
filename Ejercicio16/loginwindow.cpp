#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "userwindow.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::LoginWindow) {
    ui->setupUi(this);

    if (conectarBase()) {
        inicializarBase();
        precargarUltimoUsuario();
    }
}

LoginWindow::~LoginWindow() {
    delete ui;
}

bool LoginWindow::conectarBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usuarios.db");
    return db.open();
}

QString LoginWindow::generarMD5(const QString &texto) {
    QByteArray hash = QCryptographicHash::hash(texto.toUtf8(), QCryptographicHash::Md5);
    return QString(hash.toHex());
}

void LoginWindow::inicializarBase() {
    QSqlQuery crear;
    crear.exec("CREATE TABLE IF NOT EXISTS usuarios ("
               "usuario TEXT PRIMARY KEY, "
               "clave_md5 TEXT, "
               "nombre TEXT, "
               "ultimo_ingreso TEXT, "
               "ultimo_logueo BOOLEAN)");

    QSqlQuery verificar("SELECT COUNT(*) FROM usuarios WHERE usuario = 'admin'");
    if (verificar.next() && verificar.value(0).toInt() == 0) {
        QSqlQuery insertar;
        insertar.prepare("INSERT INTO usuarios "
                         "(usuario, clave_md5, nombre, ultimo_ingreso, ultimo_logueo) "
                         "VALUES (?, ?, ?, ?, ?)");
        insertar.addBindValue("admin");
        insertar.addBindValue(generarMD5("1234"));
        insertar.addBindValue("Administrador");
        insertar.addBindValue("Nunca");
        insertar.addBindValue(true);
        insertar.exec();
    }
}

void LoginWindow::precargarUltimoUsuario() {
    QSqlQuery query("SELECT usuario FROM usuarios WHERE ultimo_logueo = 1");
    if (query.next()) {
        ui->usuarioLineEdit->setText(query.value(0).toString());
    }
}

void LoginWindow::on_loginButton_clicked() {
    QString usuario = ui->usuarioLineEdit->text().trimmed();
    QString claveHash = generarMD5(ui->claveLineEdit->text());

    QSqlQuery query;
    query.prepare("SELECT nombre, ultimo_ingreso FROM usuarios WHERE usuario = ? AND clave_md5 = ?");
    query.addBindValue(usuario);
    query.addBindValue(claveHash);

    if (query.exec() && query.next()) {
        QString nombre = query.value(0).toString();
        QString ultimoIngreso = query.value(1).toString();

        QString ahora = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        QSqlQuery limpiar;
        limpiar.exec("UPDATE usuarios SET ultimo_logueo = 0");

        QSqlQuery actualizar;
        actualizar.prepare("UPDATE usuarios SET ultimo_ingreso = ?, ultimo_logueo = 1 WHERE usuario = ?");
        actualizar.addBindValue(ahora);
        actualizar.addBindValue(usuario);
        actualizar.exec();

        UserWindow *ventana = new UserWindow(nombre, ultimoIngreso);
        ventana->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Credenciales incorrectas");
    }
}

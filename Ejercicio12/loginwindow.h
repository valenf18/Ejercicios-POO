#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_loginButton_clicked();
    void respuestaApi(QNetworkReply *reply);

private:
    Ui::LoginWindow *ui;
    QNetworkAccessManager *networkManager;
    void obtenerTemperatura();
};

#endif // LOGINWINDOW_H

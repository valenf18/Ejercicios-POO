#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class QLineEdit;
class QPushButton;
class QLabel;
class QPixmap;

class LoginWindow : public QWidget {
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void onLoginClicked();
    void onImageDownloaded(QNetworkReply *reply);

private:
    QLineEdit* usuarioEdit;
    QLineEdit* claveEdit;
    QPushButton* loginButton;
    QLabel* fondoLabel;

    QNetworkAccessManager* manager;
    QPixmap fondoPixmap;
    bool imagenCargada = false;

    void descargarImagenFondo();
};

#endif // LOGINWINDOW_H

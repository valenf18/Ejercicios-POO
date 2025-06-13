#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWindow), manager(new QNetworkAccessManager(this)) {
    ui->setupUi(this);

    connect(ui->downloadButton, &QPushButton::clicked, this, &MainWindow::onDownloadClicked);
    connect(manager, &QNetworkAccessManager::finished, this, &MainWindow::onHtmlDownloaded);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onDownloadClicked() {
    QString urlText = ui->urlEdit->text().trimmed();
    if (urlText.isEmpty()) return;

    downloadDir = QFileDialog::getExistingDirectory(this, "Seleccionar carpeta de descarga");
    if (downloadDir.isEmpty()) return;

    QUrl url(urlText);
    if (!url.isValid()) {
        QMessageBox::warning(this, "Error", "URL inválida.");
        return;
    }

    ui->logText->append("Descargando HTML de: " + url.toString());
    manager->get(QNetworkRequest(url));
}

void MainWindow::onHtmlDownloaded(QNetworkReply *reply) {
    QUrl baseUrl = reply->url();
    QString html = reply->readAll();
    reply->deleteLater();

    QRegularExpression re("(?i)(?:src|href)=[\"']([^\"'>]+)[\"']");
    QRegularExpressionMatchIterator i = re.globalMatch(html);

    while (i.hasNext()) {
        auto match = i.next();
        QString resourceUrl = match.captured(1);
        QUrl fullUrl = baseUrl.resolved(QUrl(resourceUrl));
        downloadResource(fullUrl);
    }
}

void MainWindow::downloadResource(const QUrl &url) {
    QNetworkReply *reply = manager->get(QNetworkRequest(url));
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        onResourceDownloaded(reply);
    });
}

void MainWindow::onResourceDownloaded(QNetworkReply *reply) {
    QUrl url = reply->url();
    QString filename = url.fileName();
    if (filename.isEmpty()) filename = "index.html";

    QString fullPath = downloadDir + "/" + filename;

    QFile file(fullPath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(reply->readAll());
        file.close();
        ui->logText->append("Guardado: " + fullPath);
    } else {
        ui->logText->append("Error al guardar: " + fullPath);
    }

    reply->deleteLater();
}

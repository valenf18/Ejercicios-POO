#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow ventana;
    ventana.showMaximized();

    return app.exec();
}

#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Pintura w;
    w.resize(800, 600);
    w.show();

    return app.exec();
}

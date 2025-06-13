#include <QCoreApplication>
#include <QElapsedTimer>
#include <QDebug>
#include "sensor.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Sensor sensor;

    const int repeticiones = 10'000'000;
    int suma = 0;
    double sumaNormalizada = 0.0;

    QElapsedTimer timer;

    // getValorBruto()
    timer.start();
    for (int i = 0; i < repeticiones; ++i)
        suma += sensor.getValorBruto();
    qDebug() << "getValorBruto():" << timer.elapsed() << "ms";

    // getValorBrutoOffline()
    suma = 0;
    timer.restart();
    for (int i = 0; i < repeticiones; ++i)
        suma += sensor.getValorBrutoOffline();
    qDebug() << "getValorBrutoOffline():" << timer.elapsed() << "ms";

    // getValorNormalizado()
    sumaNormalizada = 0.0;
    timer.restart();
    for (int i = 0; i < repeticiones; ++i)
        sumaNormalizada += sensor.getValorNormalizado();
    qDebug() << "getValorNormalizado():" << timer.elapsed() << "ms";

    // getValorNormalizadoOffline()
    sumaNormalizada = 0.0;
    timer.restart();
    for (int i = 0; i < repeticiones; ++i)
        sumaNormalizada += sensor.getValorNormalizadoOffline();
    qDebug() << "getValorNormalizadoOffline():" << timer.elapsed() << "ms";

    return 0;
}

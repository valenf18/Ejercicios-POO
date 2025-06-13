#include "pintura.h"
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>

Pintura::Pintura(QWidget *parent)
    : QWidget(parent), colorActual(Qt::black), grosorPincel(5), dibujando(false) {

    canvas = QPixmap(800, 600);
    canvas.fill(Qt::white);
    setWindowTitle("Pizarra - Ejercicio 14");
    setFocusPolicy(Qt::StrongFocus); // Para recibir eventos de teclado
}

void Pintura::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, canvas);
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dibujando = true;
        lastPoint = event->pos();
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if (dibujando) {
        QPainter painter(&canvas);
        painter.setPen(QPen(colorActual, grosorPincel, Qt::SolidLine, Qt::RoundCap));
        painter.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        update(); // Redibujar
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0)
        grosorPincel = std::min(grosorPincel + 1, 50);
    else
        grosorPincel = std::max(grosorPincel - 1, 1);
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_R:
        colorActual = Qt::red;
        break;
    case Qt::Key_G:
        colorActual = Qt::green;
        break;
    case Qt::Key_B:
        colorActual = Qt::blue;
        break;
    case Qt::Key_Escape:
        limpiarCanvas();
        break;
    }
    update();
}

void Pintura::limpiarCanvas() {
    canvas.fill(Qt::white);
    update();
}


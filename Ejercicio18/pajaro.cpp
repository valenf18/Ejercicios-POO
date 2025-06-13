#include "pajaro.h"
#include <QPainter>

Pajaro::Pajaro(QWidget *parent) : QWidget(parent) {
    setFixedSize(30, 30);
    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &Pajaro::mover);
    moveTimer->start(30);
}

Pajaro::~Pajaro() {}

void Pajaro::mover() {
    move(x() - 5, y());
    if (x() + width() < 0) deleteLater();
}

void Pajaro::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setBrush(Qt::red);
    p.drawEllipse(rect());
}

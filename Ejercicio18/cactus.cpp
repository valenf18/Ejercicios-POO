#include "cactus.h"
#include <QPainter>

Cactus::Cactus(QWidget *parent) : QWidget(parent) {
    setFixedSize(20, 50);
}

void Cactus::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setBrush(Qt::darkCyan);
    p.drawRect(rect());
}

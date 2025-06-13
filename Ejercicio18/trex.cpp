#include "trex.h"
#include <QPainter>
#include <QTimer>

TRex::TRex(QWidget *parent) : QWidget(parent), yPosition(200), isJumping(false) {
    setFixedSize(40, 40);
}

void TRex::saltar() {
    if (!isJumping) {
        isJumping = true;
        move(x(), y() - 50);
        QTimer::singleShot(500, [this]() {
            move(x(), y() + 50);
            isJumping = false;
        });
    }
}

void TRex::agacharse() {
    resize(40, 20);
    QTimer::singleShot(500, [this]() {
        resize(40, 40);
    });
}

void TRex::avanzar() {
    move(x() + 10, y());
}

void TRex::frenar() {
    move(x() - 10, y());
}

void TRex::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setBrush(Qt::darkGreen);
    p.drawRect(rect());
}

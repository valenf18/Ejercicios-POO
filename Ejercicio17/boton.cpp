#include "boton.h"
#include <QPainter>
#include <QMouseEvent>

Boton::Boton(QWidget *parent)
    : QWidget(parent), colorFondo(Qt::gray), texto("Botón") {
    setMinimumSize(100, 50);
}

void Boton::colorear(Boton::Color color) {
    switch (color) {
    case Rojo:       colorFondo = QColor("#E74C3C"); break;
    case Violeta:    colorFondo = QColor("#8E44AD"); break;
    case VerdeClaro: colorFondo = QColor("#2ECC71"); break;
    case Celeste:    colorFondo = QColor("#3498DB"); break;
    case VerdeAgua:  colorFondo = QColor("#1ABC9C"); break;
    }
    update();
}

void Boton::setTexto(const QString &t) {
    texto = t;
    update();
}

void Boton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(colorFondo);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());

    // Texto blanco, centrado
    painter.setPen(Qt::white);
    QFont fuente("Segoe UI", 12, QFont::Bold);
    painter.setFont(fuente);
    painter.drawText(rect(), Qt::AlignCenter, texto);
}

void Boton::mousePressEvent(QMouseEvent *) {
    emit signal_clic();
}

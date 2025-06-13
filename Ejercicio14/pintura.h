#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QPixmap>
#include <QColor>
#include <QPoint>

class Pintura : public QWidget {
    Q_OBJECT

public:
    explicit Pintura(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QPixmap canvas;
    QPoint lastPoint;
    QColor colorActual;
    int grosorPincel;
    bool dibujando;
    void limpiarCanvas();
};

#endif // PINTURA_H

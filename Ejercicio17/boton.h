#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QColor>

class Boton : public QWidget {
    Q_OBJECT

public:
    enum Color {
        Rojo,
        Violeta,
        VerdeClaro,
        Celeste,
        VerdeAgua
    };

    explicit Boton(QWidget *parent = nullptr);

    void colorear(Color color);
    void setTexto(const QString &texto);

signals:
    void signal_clic();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QColor colorFondo;
    QString texto;
};

#endif // BOTON_H

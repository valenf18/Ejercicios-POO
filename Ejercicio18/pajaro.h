#ifndef PAJARO_H
#define PAJARO_H

#include <QWidget>
#include <QTimer>

class Pajaro : public QWidget {
    Q_OBJECT

public:
    explicit Pajaro(QWidget *parent = nullptr);
    ~Pajaro();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void mover();

private:
    QTimer *moveTimer;
};

#endif // PAJARO_H

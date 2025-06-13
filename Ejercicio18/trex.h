#ifndef TREX_H
#define TREX_H

#include <QWidget>

class TRex : public QWidget {
    Q_OBJECT

public:
    explicit TRex(QWidget *parent = nullptr);
    void saltar();
    void agacharse();
    void avanzar();
    void frenar();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int yPosition;
    bool isJumping;
};

#endif // TREX_H

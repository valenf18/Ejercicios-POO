#ifndef CACTUS_H
#define CACTUS_H

#include <QWidget>

class Cactus : public QWidget {
    Q_OBJECT

public:
    explicit Cactus(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CACTUS_H

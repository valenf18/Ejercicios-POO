#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QTimer>
#include "trex.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void updateGame();
    void spawnPajaro();

private:
    Ui::GameWindow *ui;
    QTimer *mainTimer;
    QTimer *pajaroSpawner;
    TRex *trex;
    QList<QWidget*> obstacles;
    void checkCollisions();
    void gameOver();
};

#endif // GAMEWINDOW_H

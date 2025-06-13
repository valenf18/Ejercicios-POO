#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "pajaro.h"
#include "cactus.h"
#include <QKeyEvent>
#include <QMessageBox>

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::GameWindow) {
    ui->setupUi(this);

    setFixedSize(800, 300);

    trex = new TRex(this);
    trex->move(50, 200);
    trex->show();

    mainTimer = new QTimer(this);
    connect(mainTimer, &QTimer::timeout, this, &GameWindow::updateGame);
    mainTimer->start(30);

    pajaroSpawner = new QTimer(this);
    connect(pajaroSpawner, &QTimer::timeout, this, &GameWindow::spawnPajaro);
    pajaroSpawner->start(5000);
}

GameWindow::~GameWindow() {
    delete ui;
}

void GameWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Space) trex->saltar();
    else if (event->key() == Qt::Key_Down) trex->agacharse();
    else if (event->key() == Qt::Key_Left) trex->frenar();
    else if (event->key() == Qt::Key_Right) trex->avanzar();
}

void GameWindow::updateGame() {
    checkCollisions();
}

void GameWindow::spawnPajaro() {
    Pajaro *p = new Pajaro(this);
    p->move(800, 200);
    p->show();
    obstacles.append(p);
}

void GameWindow::checkCollisions() {
    for (QWidget *obs : obstacles) {
        if (trex->geometry().intersects(obs->geometry())) {
            gameOver();
            break;
        }
    }
}

void GameWindow::gameOver() {
    mainTimer->stop();
    pajaroSpawner->stop();
    QMessageBox::information(this, "Game Over", "¡Perdiste!");
}

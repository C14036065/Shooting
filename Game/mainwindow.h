#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QString>
#include <QMessageBox>
#include <string.h>

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "health.h"
#include "score.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTimer *timer;
    QTimer *ctimer;

public slots:
    virtual void mousePressEvent(QMouseEvent *e);

    void game();
    void minusPlayer();
    void minusEnemy();
    void win();
    void lose();
    void countTime();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Player *player;
    Enemy *enemy;
    Score *score;

    int second;
    int minute;

private slots:
    void gameStart();
    void conti();
    void on_pauseButton_clicked();
    void on_endButton_clicked();

signals:
    void dialogShow();
    void playagain();
    void quit();
};

#endif // MAINWINDOW_H

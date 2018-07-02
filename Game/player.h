#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player : public Character
{
public:
    Player();
    QTimer *t;

public slots:
    void move();
    void shoot();
    void hurt();
    void setHpSp();
    void spAttack();
    void recoversp();

    void mousePressEvent(QMouseEvent *e);

private:
    bool alreadySet;
    Health *h;
    Special *s;
};

#endif // PLAYER_H

#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character
{
public:
    Enemy();
    QTimer *t;
    QTimer *bt;

public slots:
    void move();
    void shoot();
    void hurt();
    void setHpSp();
    void spAttack();
    void recoversp();

    void horizontal_move();

private:
    bool reverse;
    bool alreadySet;
    Health *h;
    Special *s;

};

#endif // ENEMY_H

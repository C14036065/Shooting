#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItemAnimation>
#include <QCursor>
#include <QList>
#include <QTimer>
#include <QTimeLine>
#include "bullet.h"
#include "health.h"
#include "special.h"

class Character : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Character();

public slots:
    virtual void move() = 0;
    virtual void shoot() = 0;
    virtual void hurt() = 0;
    virtual void setHpSp() = 0;
    virtual void spAttack() = 0;
    virtual void recoversp() = 0;

protected:
    int hp;
    double sp;
};


#endif // CHARACTER_H

#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QString>
#include <QList>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Bullet();
    Bullet(QString s);

public slots:
    void clickFire();
    void moveToPlayer();
    void moveToEnemy();
    void moveToRight();
    void moveToLeft();
    void moveToUp();
    void moveToDown();
    void hitPlayer();
    void hitEnemy();

};

#endif // BULLET_H

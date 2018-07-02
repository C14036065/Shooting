#include "bullet.h"
#include "enemy.h"
#include "player.h"
#include "mainwindow.h"

extern MainWindow *w;

Bullet::Bullet()
{

}

Bullet::Bullet(QString s)
{
    if (s.toStdString() == "player")
    {
        setPixmap(QPixmap(":/player-bullet.png"));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(moveToEnemy()));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(hitEnemy()));
    }
    else if (s.toStdString() == "click")
    {
        setPixmap(QPixmap(":/click-bullet.png"));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(clickFire()));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(hitEnemy()));
    }
    else if (s.toStdString() == "enemy")
    {
        setPixmap(QPixmap(":/enemy-bullet.png"));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(moveToPlayer()));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(hitPlayer()));
    }
    else if (s.toStdString() == "special_right")
    {
        setPixmap(QPixmap(":/sp-bullet.png"));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(moveToLeft()));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(hitPlayer()));
    }
    else if (s.toStdString() == "special_left")
    {
        setPixmap(QPixmap(":/sp-bullet.png"));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(moveToRight()));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(hitPlayer()));
    }
    else if (s.toStdString() == "special_up")
    {
        setPixmap(QPixmap(":/sp-bullet.png"));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(moveToDown()));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(hitPlayer()));
    }
    else if (s.toStdString() == "special_down")
    {
        setPixmap(QPixmap(":/sp-bullet.png"));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(moveToUp()));
        connect(w->timer, SIGNAL(timeout()), this, SLOT(hitPlayer()));
    }
}

void Bullet::clickFire()
{
    setPos(x(), y()-3);

    if (y() < 0)
    {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveToPlayer()
{
    setPos(x(), y()+3);

    if (y() >= 600)
    {
        this->scene()->removeItem(this);
        delete this;
    }

}

void Bullet::moveToEnemy()
{
    setPos(x(), y()-3);

    if (y() < 0)
    {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveToRight()
{
    setPos(x()+3, y());

    if (x() >= 900)
    {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveToLeft()
{
    setPos(x()-3, y());

    if (x() <= 0)
    {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveToUp()
{
    setPos(x(), y()-3);

    if (y() < 0)
    {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::moveToDown()
{
    setPos(x(), y()+3);

    if (y() >= 600)
    {
        this->scene()->removeItem(this);
        delete this;
    }
}


void Bullet::hitEnemy()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();
    for (int i = 0; i < collidingItems().size(); ++i)
    {
        if (typeid(*(colliding_item[i])) == typeid(Enemy))
        {
            w->minusEnemy();
            scene()->removeItem(this);
            delete this;
        }
        else if (typeid(*(colliding_item[i])) == typeid(Bullet))
        {
            scene()->removeItem(this);
            delete this;

        }
    }
}


void Bullet::hitPlayer()
{
    QList<QGraphicsItem *> colliding_item = collidingItems();
    for (int i = 0; i < collidingItems().size(); ++i)
    {
        if (typeid(*(colliding_item[i])) == typeid(Player))
        {
            w->minusPlayer();
            scene()->removeItem(this);
            delete this;
        }
        else if (typeid(*(colliding_item[i])) == typeid(Bullet))
        {
            scene()->removeItem(colliding_item[i]);
            delete colliding_item[i];
        }
    }
}

#include "player.h"
#include "mainwindow.h"

extern MainWindow *w;

Player::Player()
{
    this->setPixmap(QPixmap(":/paper-plane.png"));
    hp = 64;
    sp = 64;
    alreadySet = false;

    h = new Health();
    h->setValue(hp);
    s = new Special();
    s->setValue(sp);

    t = new QTimer();
    connect(t, SIGNAL(timeout()), this, SLOT(shoot()));
    connect(t, SIGNAL(timeout()), this, SLOT(recoversp()));
}

void Player::move()
{
    QPoint m_pos = QCursor::pos();
    int xx = m_pos.x() - 2.5*pixmap().width();
    int yy = m_pos.y() - 2*pixmap().height();

    if (xx <= 0)
    {
        xx = 0;
    }
    else if (xx >= 900-pixmap().width())
    {
        xx = 900 - pixmap().width();
    }

    if (yy <= 0)
    {
        yy = 0;
    }
    else if (yy >= 600-pixmap().height())
    {
        yy = 600 - pixmap().height();
    }

    setPos(xx, yy);
    setHpSp();

    QList<QGraphicsItem *> colliding_item = collidingItems();
    for (int i = 0; i < collidingItems().size(); ++i)
    {
        if (typeid(*(colliding_item[i])) == typeid(Enemy))
        {
            w->lose();
        }
    }
}

void Player::shoot()
{
    Bullet *b = new Bullet(QString("player"));
    b->setPos(x() + pixmap().width()/3 , y() - pixmap().height()/2);
    this->scene()->addItem(b);
}

void Player::setHpSp()
{
    if (alreadySet == false)
    {
        this->scene()->addItem(h);
        this->scene()->addItem(s);
        alreadySet = true;
    }

    h->setPos(x(), y() + pixmap().height());
    s->setPos(x(), y() + pixmap().height() + 10);
}

void Player::hurt()
{

    hp -= 4;
    h->setValue(hp);

    if (hp <= 0)
    {
        scene()->removeItem(h);
        delete h;
        scene()->removeItem(s);
        delete s;
        scene()->removeItem(this);
        delete this;
        w->lose();
        return;
    }

}

void Player::spAttack()
{
    if (sp >= 16)
    {
        QList<QGraphicsItem*> all = scene()->items();

        for (int i = 0; i < scene()->items().size(); i++)
        {
            if (typeid(*(all[i])) == typeid(Bullet))
            {
                scene()->removeItem(all[i]);
                delete all[i];
            }
        }

        sp -= 16;
        setHpSp();
    }

}

void Player::recoversp()
{
    sp++;
    if (sp >= 64)
    {
        sp = 64;
    }

    s->setValue(sp);

}

#include "enemy.h"
#include "mainwindow.h"

extern MainWindow *w;

Enemy::Enemy()
{
    this->setPixmap(QPixmap(":/jupiter.png"));
    hp = 64;
    sp = 64;
    reverse = false;
    alreadySet = false;

    h = new Health();
    h->setValue(hp);
    s = new Special();
    s->setValue(sp);

    t = new QTimer();
    bt = new QTimer();

    connect(t, SIGNAL(timeout()), this, SLOT(move()));
    connect(bt, SIGNAL(timeout()), this, SLOT(shoot()));
    connect(bt, SIGNAL(timeout()), this, SLOT(recoversp()));
}


void Enemy::move()
{
    horizontal_move();

    int xx = x();
    if (xx%250 == 0 && sp >= 16)
    {
        sp -= 16;
        s->setValue(sp);
        spAttack();
    }

    setHpSp();
}


void Enemy::shoot()
{
    Bullet *b = new Bullet(QString("enemy"));
    b->setPos(x() + pixmap().width()/3 , y() + pixmap().height());
    this->scene()->addItem(b);
}

void Enemy::setHpSp()
{
    if (alreadySet == false)
    {
        this->scene()->addItem(h);
        this->scene()->addItem(s);
        alreadySet = true;
    }

    h->setPos(x(), y() - 15);
    s->setPos(x(), y() - 25);
}

void Enemy::hurt()
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
        w->win();
        return;
    }
}

void Enemy::spAttack()
{
    Bullet *bl[5];
    Bullet *br[5];
    Bullet *bu[5];
    Bullet *bd[5];

    for (int i = 0; i < 5; i++)
    {
        bl[i] = new Bullet(QString("special_left"));
        bl[i]->setPos(0, 550 - i*50);
        br[i] = new Bullet(QString("special_right"));
        br[i]->setPos(950, 100 + i*50);
        bu[i] = new Bullet(QString("special_up"));
        bu[i]->setPos(100 + i*100, 0);
        bd[i] = new Bullet(QString("special_down"));
        bd[i]->setPos(850 - i*100, 550);

        this->scene()->addItem(bl[i]);
        this->scene()->addItem(br[i]);
        this->scene()->addItem(bu[i]);
        this->scene()->addItem(bd[i]);
    }

}

void Enemy::recoversp()
{
    sp++;
    if (sp >= 64)
    {
        sp = 64;
    }

    s->setValue(sp);
}

void Enemy::horizontal_move()
{
    if (reverse)
    {
        if (x()-1 <= 0)
        {
            reverse = false;
        }
        setPos(x()-1, y());
    }
    else
    {
        if (x()+1+pixmap().width() >= 900)
        {
            reverse = true;
        }
        setPos(x()+1, y());
    }

}



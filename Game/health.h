#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>

class Health : public QGraphicsRectItem
{
public:
    Health(QGraphicsItem * parent = 0);
    void setValue(int h);

private:
    int health;
};

#endif // HEALTH_H

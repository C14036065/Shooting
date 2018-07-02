#include "health.h"

Health::Health(QGraphicsItem * parent) : QGraphicsRectItem(parent)
{
    health = 0;
    setRect(0, 0, health, 10);
    setPen(Qt::NoPen);
    setBrush(Qt::green);
}

void Health::setValue(int h)
{
    health = h;
    setRect(0, 0, health, 10);
}

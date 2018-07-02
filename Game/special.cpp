#include "special.h"

Special::Special(QGraphicsItem * parent) : QGraphicsRectItem(parent)
{
    special = 0;
    setRect(0, 0, special, 10);
    setPen(Qt::NoPen);
    setBrush(Qt::cyan);
}

void Special::setValue(double s)
{
    special = s;
    setRect(0, 0, special, 10);
}


#ifndef SPECIAL_H
#define SPECIAL_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPainter>

class Special : public QGraphicsRectItem
{
public:
    Special(QGraphicsItem * parent = 0);
    void setValue(double s);

private:
    double special;
};

#endif // SPECIAL_H

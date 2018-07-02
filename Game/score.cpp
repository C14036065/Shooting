#include "score.h"
#include <QDebug>
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    s = 0;
    setPlainText(QString("Score: ") + QString::number(s));
    setDefaultTextColor(Qt::darkBlue);
    setFont(QFont("Ubuntu", 20));
}

void Score::increase()
{
    s += 10;
    setPlainText(QString("Score: ") + QString::number(s));
}

void Score::kill()
{
    s += 100;
    setPlainText(QString("Score: ") + QString::number(s));
}

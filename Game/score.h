#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QFont>
#include <QTimer>

class Score : public QGraphicsTextItem
{

public:
    Score(QGraphicsItem * parent = 0);
    void increase();
    void kill();

private:
    int s;
};

#endif // SCORE_H

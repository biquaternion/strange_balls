#ifndef BALL_H
#define BALL_H

#include <QVector2D>
#include "ballitem.h"

class BallItem;

class Ball {
public:
    Ball(BallItem *item = nullptr);
    QVector2D a;
    QVector2D v;
    QVector2D x;
    float     m {1.0};
    float     t;
    void setItem(BallItem *);
    void notifyItem();
private:
    BallItem *_item;
    void init();
};

typedef std::list<Ball> Balls;

#endif // BALL_H

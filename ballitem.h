#ifndef BALLITEM_H
#define BALLITEM_H

#include <QRectF>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "ball.h"

class Ball;

class BallItem : public QGraphicsItem {
public:
    explicit BallItem(Ball &state, QGraphicsItem *parent = 0);
    BallItem(float x, float y);
    virtual ~BallItem();
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    bool move() const { return _move; }
protected:
    virtual void advance(int phase) override;
private:
    void init();
    Ball *_state;
    QRectF     _rect;
    QColor     _color;
    bool       _move;
};
//typedef QList<Ball*> BallsQ;
//typedef std::list<BallItem*> BallItems;


#endif // BALLITEM_H

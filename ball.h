#ifndef BALL_H
#define BALL_H

#include <QRectF>
#include <QPainter>
#include <QVector2D>
#include <QGraphicsItem>

struct BallState {
    QVector2D a;
    QVector2D v;
    QVector2D x;
    float     m {1};
};

class Ball : public QGraphicsItem {
public:
    Ball();
    Ball(float x, float y);
    ~Ball();
    virtual QRectF boundingRect() const override;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void setState(const BallState &state) { _state = state; }
    BallState state() const { return _state; }
    BallState &state() { return _state; }
protected:
    void advance(int phase);
private:
    void init();
    BallState _state;
    QRectF    _rect;
    QColor    _color;
};
typedef QList<Ball*> Balls;

#endif // BALL_H

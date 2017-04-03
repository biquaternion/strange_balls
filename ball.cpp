#include "ball.h"

Ball::Ball() {
    setPos(qrand() % 256,
           qrand() % 256);
    init();
}

Ball::Ball(float x,
           float y) {
    setPos(x, y);
    init();
}

Ball::~Ball() {}

QRectF Ball::boundingRect() const {
    return _rect;
}

void Ball::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    painter->setBrush(_color);
    painter->drawEllipse(_rect);
//    painter->drawText(QPointF(3, 3), );
}

void Ball::advance(int phase) {
    if (phase == 0) {

    } else { // phase == 1
        setPos(_state.x.toPointF());
    }
}

void Ball::init() {
    _rect  = QRectF(-5, -5, 10, 10);
    _color = QColor(qrand() % 256,
                    qrand() % 256,
                    qrand() % 256);
    _state.x = QVector2D(this->pos());
    _state.v = QVector2D(0, 0);
    _state.a = QVector2D(0, 0);
}

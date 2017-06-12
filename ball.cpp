#include "ball.h"

static const QRect __rect = {-320, -320, 640, 640};

Ball::Ball(BallItem *item) :
    _item(item) {
    init();
}

void Ball::setItem(BallItem *item) {
    _item = item;
}

void Ball::notifyItem() {
    if (_item != nullptr) {
        if (!_item->move())
            _item->setPos(this->x.toPointF());
    }
}

void Ball::init() {
    x = {qrand() % __rect.width()  + __rect.left(),
         qrand() % __rect.height() + __rect.top()};
    v = {0, 0};
    a = {0, 0};
}

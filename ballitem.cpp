#include "ballitem.h"

BallItem::BallItem(Ball &state, QGraphicsItem *parent) :
    QGraphicsItem(parent) {
    _state = &state;
    setPos(_state->x.x(),
           _state->x.y());
    init();
}

BallItem::BallItem(float x,
           float y) {
    setPos(x, y);
    init();
}

BallItem::~BallItem() {}

QRectF BallItem::boundingRect() const {
    return _rect;
}

void BallItem::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget) {
    painter->setBrush(_color);
    painter->drawEllipse(_rect);
}

void BallItem::advance(int phase) {
    if (phase == 0) {

    } else { // phase == 1
        update();
    }
}

void BallItem::init() {
    _move = false;
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);
    setFlag(ItemSendsGeometryChanges);
    setAcceptDrops(true);
    _rect  = QRectF(-5, -5, 10, 10);
    _color = QColor(qrand() % 256,
                    qrand() % 256,
                    qrand() % 256);
}

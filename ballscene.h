#ifndef BALLSCENE_H
#define BALLSCENE_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class BallScene : public QGraphicsScene {
public:
    explicit BallScene(QObject *parent = 0);
protected:
//    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
//    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
//    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
//    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
//    virtual void dropEvent(QGraphicsSceneDragDropEvent *event);
//    virtual void focusInEvent(QFocusEvent *event);
//    virtual void focusOutEvent(QFocusEvent *event);
//    virtual void helpEvent(QGraphicsSceneHelpEvent *event);
//    virtual void keyPressEvent(QKeyEvent *event);
//    virtual void keyReleaseEvent(QKeyEvent *event);

//    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

//    virtual void wheelEvent(QGraphicsSceneWheelEvent *event);
//    virtual void inputMethodEvent(QInputMethodEvent *event);

//    virtual void drawBackground(QPainter *painter, const QRectF &rect);
//    virtual void drawForeground(QPainter *painter, const QRectF &rect);
//    virtual void drawItems(QPainter *painter, int numItems,
//                           QGraphicsItem *items[],
//                           const QStyleOptionGraphicsItem options[],
//                           QWidget *widget = Q_NULLPTR);

};

#endif // BALLSCENE_H

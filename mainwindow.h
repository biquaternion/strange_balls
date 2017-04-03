#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimerEvent>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QVector2D>
#include "ball.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onAddElem() {}

private:
    Ui::MainWindow *ui;
    QGraphicsScene _scene;
    Balls          _balls;
    void timerEvent(QTimerEvent*);
};

#endif // MAINWINDOW_H

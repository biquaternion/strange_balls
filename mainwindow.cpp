#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTime>
#include <QColor>
#include <QGraphicsItem>
#include <QVector2D>
#include "kinematics.h"

static const unsigned int __initialBallCount = 10;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    ui->setupUi(this);
//    _scene.setSceneRect(QRect(-320, -320, 640, 640));
//    _scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    for (int i = 0; i != __initialBallCount; ++i) {
        Ball *b = new Ball();
        b->setPos(qrand() % 640 - 320,
                  qrand() % 640 - 320);
        _balls.push_back(b);
        _scene.addItem(b);
    }

    ui->ballsView->setScene(&_scene);
    this->startTimer(40);

}

MainWindow::~MainWindow() {
    foreach (Ball *b, _balls) {
        delete b;
    }
    _balls.clear();
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *ev) {
    for (QList<Ball*>::const_iterator i = _balls.begin();
         i != _balls.end();
         ++i) {
        BallState s1 = (*i)->state();
        for (auto it = _balls.begin();
             it != _balls.end();
             ++it) {
            if (i != it) {
                BallState s2 = (*it)->state();
                QVector2D ort = (s2.x - s1.x);
                float r = ort.length();
                if (r == 0) qDebug() << "zero-length vector";
                ort /= r;
                s1.a += force(r) * ort;
            }
            intFixedStep(s1);
        }
        (*i)->setState(s1);
    }
    _scene.advance();
}

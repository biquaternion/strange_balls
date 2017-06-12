#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ballitem.h"
#include <QTime>

static const size_t __initialBallCount = 33;
static const QRect __initialRect = {-320, -320, 640, 640};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _almanac(new Almanac())
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    ui->setupUi(this);
    for (int i = 0; i != __initialBallCount; ++i) {
        Ball b;
        _state.push_back(std::move(b));
    }
    for (Balls::iterator i = _state.begin();
         i != _state.end();
         ++i) {
        BallItem *item = new BallItem(*i);
        _scene.addItem(item);
        i->setItem(item);
    }
    _almanac->init(_state);
    ui->ballsView->setScene(&_scene);
    this->startTimer(40);
}

MainWindow::~MainWindow() {
    _state.clear();
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *ev) {
    _state = _almanac->getNextState();
    for (auto it = _state.begin();
         it != _state.end(); ++it) {
        it->notifyItem();
    }
    _scene.advance();
}

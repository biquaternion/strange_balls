#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimerEvent>
#include "almanac.h"
#include "ballscene.h"
#include "ball.h"
#include <memory>

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
    BallScene _scene;
    Balls     _state;
    std::unique_ptr<Almanac> _almanac;
    void timerEvent(QTimerEvent*);
};

#endif // MAINWINDOW_H

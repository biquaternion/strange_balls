#ifndef KINEMATICS_H
#define KINEMATICS_H

#include "ball.h"
#include "integrator.h"
#include <QObject>
#include <future>

class Almanac : public QObject {
    Q_OBJECT
public:
    explicit Almanac(const Balls &s);
    Almanac();
    void init(const Balls &s);
    void  calc(Buf &buf, bool async = false);
    Balls &getState();
    Balls getNextState();
private:
    Buf     _buf1;
    Buf     _buf2;
    Buf::iterator _it;
    Integrator    _ir;
    Balls   _last;
    std::shared_future<void> _f;
};

#endif // KINEMATICS_H

#include "integrator.h"

Integrator::Integrator(float dt) :
    _dt(dt) {}

float Integrator::force(float r) {
    r /= __scale;
    return (r > 1e-3) ?
                (1.0 / r - 1.0 / (r*r)) :
                (1.0 / 1e-3 - 1.0 / (1e-6));
}

Balls Integrator::step(const Balls &s) {
    Balls result = s;
    for (auto i = result.begin();
         i != result.end();
         ++i) {
        Ball &s1 = *i;
        for (auto j = i;
             j != result.end();
             ++j) {
            if (i != j) {
                Ball &s2 = *j;
                QVector2D v = s2.x - s1.x;
                float r = v.length();
                v.normalize();
                v *= force(r);
                s1.a += v;
                s2.a -= v;
            }
            s1.v += s1.a * _dt;
            s1.x += s1.v * _dt;
            s1.a = QVector2D(0, 0);
        }
    }
    return result;
}

void Integrator::integrate(Buf &buf,
                            Balls &initial) {
    Balls &s = initial;
    for (auto i = buf.begin();
         i != buf.end();
         ++i) {
        *i = step(s);
        s = *i;
    }
}

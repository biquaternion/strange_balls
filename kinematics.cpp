#include "kinematics.h"

float force(float r) {
    return (r != 0) ? (1 / r - 1 / (r*r)) : (qrand() % 2);
}

BallState intFixedStep(BallState &s,
                       float dt) {
    s.v += s.a * dt;
    s.x += s.v * dt;
    s.a = QVector2D(0, 0);
}

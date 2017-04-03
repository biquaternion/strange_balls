#include "kinematics.h"

float force(float r) {
    return (1 / r - 1 / (r*r));
}

BallState intFixedStep(BallState &s,
                       float dt) {
    s.v += s.a * dt;
    s.x += s.v * dt;
    s.a = QVector2D(0, 0);
}

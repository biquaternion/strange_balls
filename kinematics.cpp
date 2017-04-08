#include "kinematics.h"

float force(float r) {
    return (r >= 1e-3) ? (1 / r - 1 / (r*r)) : (1 / 1e-3 - 1 / (1e-6));
}

BallState intFixedStep(BallState &s,
                       float dt) {
    s.v += s.a * dt;
    s.x += s.v * dt;
    s.a = QVector2D(0, 0);
}

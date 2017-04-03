#ifndef KINEMATICS_H
#define KINEMATICS_H

#include <list>
#include "ball.h"

float force(float r);
BallState intFixedStep(BallState &s,
                       float dt = 0.1);

#endif // KINEMATICS_H

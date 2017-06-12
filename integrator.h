#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <array>
#include "ball.h"

static const float __scale = 3.0;

constexpr size_t __bufSize = 50;
//using Buf = std::array<Balls, __bufSize>;//
typedef std::array<Balls, __bufSize> Buf;

class Integrator
{
public:
    explicit Integrator(float dt = 0.1);
    void integrate(Buf &buf,
                   Balls &initial);
    static float force(float r);
private:
    Balls step(const Balls &s);

    float _dt;
};

#endif // INTEGRATOR_H

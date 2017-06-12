#include "almanac.h"
#include <iostream>

Almanac::Almanac(const Balls &s) :
    _last(s) {
    _it = _buf1.begin();
}

Almanac::Almanac() {
    _it = _buf1.begin();
}

void Almanac::init(const Balls &s) {
    _last = s;
    calc(_buf1);
    calc(_buf2);
}

void Almanac::calc(Buf &buf, bool async) {
    if (async) {
        if (_f.valid())
            _f.wait();
        auto asyntegrate = [] (Balls &last,
                               Integrator &ir,
                               Buf &buf) {
//            std::cout << std::this_thread::get_id() << std::endl;
            ir.integrate(buf, last);
        };

        _f = std::async(std::launch::async,
                        asyntegrate,
                        std::ref(_last),
                        std::ref(_ir),
                        std::ref(buf));
    } else {
        _ir.integrate(buf, _last);
    }
}

Balls &Almanac::getState() {
    return *_it;
}

Balls Almanac::getNextState() {
    if (_it == _buf1.end()) {
        _it = _buf2.begin();
        calc(_buf1, true);
    }
    if (_it == _buf2.end()) {
        _it = _buf1.begin();
        calc(_buf2, true);
    }
    return *(_it++);
}

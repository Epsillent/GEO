#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "engine.hpp"

class Battlefield: public BaseScene {
    public:
        void on_init()override;
        void on_update(float dt)override;
};

#endif
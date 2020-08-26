#ifndef PROTECTOR_H
#define PROTECTOR_H

#include "engine.hpp"
#include "components/trigger_2d.hpp"
#include "components/sprite_2d.hpp"
#include "entities/entity.hpp"

class Protector: public Entity {
    private:
        Sprite2D *m_c_body;
    public:
        Protector(uint8 &cell, Side side);
};

#endif
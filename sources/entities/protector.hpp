#ifndef PROTECTOR_H
#define PROTECTOR_H

#include "engine.hpp"
#include "components/trigger_2d.hpp"
#include "components/sprite_2d.hpp"
#include "entities/entity.hpp"

class Protector: public Entity {
    private:
        int m_health=5;
        Sprite2D *m_c_body;
    public:
        Protector(sf::Vector2f coordinates, Side side);
};

#endif
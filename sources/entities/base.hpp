#ifndef BASE_H
#define BASE_H

#include "engine.hpp"
#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"

class Base: public Entity {
    private:
        int m_health;
        Sprite2D *m_body;
    public:
        Base();
        void on_update(float dt);
};

#endif
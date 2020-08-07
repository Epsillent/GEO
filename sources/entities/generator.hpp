#ifndef GENERATOR_H
#define GENERATOR_H

#include "entities/entity.hpp"

class Generator: public Entity {
    private:    
        Sprite2D *body;
        float m_spawn_rate;
    public:
        Generator(float spawn_rate);
};

#endif
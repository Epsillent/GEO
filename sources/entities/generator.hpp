#ifndef GENERATOR_H
#define GENERATOR_H

#include "entities/entity.hpp"
#include "entities/resources.hpp"
#include "ui/ui.hpp"

class Generator: public Entity {
    private:    
        Sprite2D *body;
        float m_spawn_rate;
        float timer=0;
        Resources *m_resources_to_update;
    public:
        Generator(uint8 &cell, Side side, Resources *resources_to_update );
        void on_update(float dt)override;
};

#endif
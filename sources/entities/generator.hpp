#ifndef GENERATOR_H
#define GENERATOR_H

#include "entities/entity.hpp"
#include "entities/resources.hpp"

class Generator: public Entity {
    private:    
        Sprite2D *body;
        float m_spawn_rate;
        float timer=0;
    public:
        Generator(float spawn_rate, Resources *resources_to_update);
        void on_update(float dt)override;
        
};

#endif
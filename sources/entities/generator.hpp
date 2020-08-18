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
        Generator(float spawn_rate, Resources *resources_to_update, sf::Vector2f coordinates, Side side);
        void on_update(float dt)override;
};

#endif
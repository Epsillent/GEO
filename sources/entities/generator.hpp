#ifndef GENERATOR_H
#define GENERATOR_H

#include "entities/entity.hpp"
#include "entities/resources.hpp"
#include "ui/ui.hpp"

class Generator: public Entity {
    NETWORK_CLASS(Generator,Entity)
    private:    
        Sprite2D *body;
        float timer;
    public:
        Generator() = default;
        void on_introduce()override;
        void on_update(float dt)override;
        void on_network_translate(const sf::Vector2f &position)override;
};

#endif
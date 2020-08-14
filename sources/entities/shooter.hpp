#ifndef SHOOTER_H
#define SHOOTER_H

#include "engine.hpp"
#include "components/particle_system.hpp"
#include "entities/entity.hpp"

class Shooter: public Entity {
    private:
        int shooting_speed=1;
        int health=5;
        Sprite2D *m_body;
        float timer = 0;
        ParticleSystemProperties bullet_partical_sys_pr;
        float bullet_speed = 350; 
        sf::Vector2f m_coordinates;
        sf::Vector2f m_direction;
    public:
        Shooter(sf::Vector2f coordinates, sf::Vector2f direction);
        void on_update(float dt)override;
};

#endif
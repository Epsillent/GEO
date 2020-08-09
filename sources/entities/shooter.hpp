#ifndef SHOOTER_H
#define SHOOTER_H

#include "engine.hpp"
#include "components/particle_system.hpp"

class Shooter: public GameObject{
    private:
        int shooting_speed=1;
        int health=5;
        Sprite2D *m_body;
        float timer = 0;
        ParticleSystemProperties bullet_partical_sys_pr;
        float bullet_speed = 350; 
        sf::Vector2f m_coordinates;
    public:
        Shooter(sf::Vector2f coordinates);
        void on_update(float dt)override;
};

#endif
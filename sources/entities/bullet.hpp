#ifndef BULLET_H
#define BULLET_H

#include "engine.hpp"
#include "components/particle_system.hpp"

class Bullet: public GameObject {
    private:
        ParticleSystem *c_partical_system;
        Trigger2D *m_c_trigger_2d;
        sf::Vector2f m_direction = sf::Vector2f(10,10);
        float m_timer=0;
        float m_speed=50;
    public:
        Bullet(sf::Vector2f direction, sf::Vector2f coordinates, float speed, ParticleSystemProperties &pr_partical_system);
        void on_update(float dt)override;
        void on_collided(Trigger2D other);
};


#endif 
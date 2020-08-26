#ifndef BULLET_H
#define BULLET_H

#include "engine.hpp"
#include "components/particle_system.hpp"
#include "entities/entity.hpp"

class Bullet: public GameObject{
    private:
        Side m_side;
        sf::Vector2f m_translation;

        float m_timer;

        ParticleSystem *c_partical_system;
        Trigger2D *m_c_trigger_2d;
  
    public:
        Bullet(Side side, const sf::Vector2f &translation, ParticleSystemProperties &pr_partical_system);
        void on_update(float dt)override;
        void on_collided(Trigger2D other);
        Side side(){return m_side;}
};


#endif 
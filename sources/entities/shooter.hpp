#ifndef SHOOTER_H
#define SHOOTER_H

#include "engine.hpp"
#include "components/particle_system.hpp"
#include "entities/entity.hpp"

class Shooter: public Entity {
private:
    sf::Vector2f m_direction;
    float timer = 0;

    ParticleSystemProperties bullet_partical_sys_pr;
    Sprite2D *m_body;
public:
    Shooter(uint8 &cell, Side side);
    void on_update(float dt) override;
};

#endif
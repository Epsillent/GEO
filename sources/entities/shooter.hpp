#ifndef SHOOTER_H
#define SHOOTER_H

#include "engine.hpp"
#include "components/particle_system.hpp"
#include "entities/entity.hpp"

class Shooter: public Entity {
    NETWORK_CLASS(Shooter,Entity)
private:
    sf::Vector2f m_direction;
    float timer;

    ParticleSystemProperties bullet_partical_sys_pr;
    Sprite2D *m_body;
public:
    Shooter() = default;
    void on_introduce()override;
    void on_update(float dt) override;
    void on_network_translate(const sf::Vector2f &position)override;
};

#endif
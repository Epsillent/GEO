#include "entities/bullet.hpp"
#include "components/particle_system.hpp"

Bullet::Bullet(sf::Vector2f direction, sf::Vector2f coordinates, float speed, ParticleSystemProperties &pr_partical_system){
    m_direction = direction;
    translate(coordinates.x, coordinates.y-50);
    c_partical_system = component_add<ParticleSystem>(pr_partical_system);
    m_speed = speed;
    //c_trigger_2d = component_add<Trigger2D>(pr_trigger_2d);
}

void Bullet::on_update(float dt){
    m_timer += dt;
    if (m_timer > 2) {
        destroy();
    }
    translate(dt*m_direction.x*m_speed, dt*m_direction.y*m_speed);
}
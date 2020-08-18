#include "entities/bullet.hpp"
#include "components/particle_system.hpp"
#include "components/trigger_2d.hpp"

Bullet::Bullet(sf::Vector2f direction, sf::Vector2f coordinates, float speed, ParticleSystemProperties &pr_partical_system): Entity(5) {
    m_direction = direction;
    translate(coordinates);
    c_partical_system = component_add<ParticleSystem>(pr_partical_system);
    m_speed = speed;
    Trigger2DProperties pr_trigger_2d;
    pr_trigger_2d.callback = CALLBACK(&Bullet::on_collided);
    pr_trigger_2d.size = Trigger2D::size(30, 30);
    m_c_trigger_2d->set_properties(pr_trigger_2d);
    set_tag("bullet");
}

void Bullet::on_update(float dt) {
    m_timer += dt;
    if (m_timer > 2) {
        destroy();
    }
    translate(dt*m_direction.x*m_speed, dt*m_direction.y*m_speed);
}

void Bullet::on_collided(Trigger2D other) {
    if(m_side != static_cast<Entity*>( other.owner() )->m_side && other.owner()->tag() != "bullet" ) {
        destroy();
    }
}

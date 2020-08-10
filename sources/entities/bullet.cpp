#include "entities/bullet.hpp"
#include "components/particle_system.hpp"
#include "components/trigger_2d.hpp"

Bullet::Bullet(sf::Vector2f direction, sf::Vector2f coordinates, float speed, ParticleSystemProperties &pr_partical_system){
    Trigger2DProperties pr_trigger_2d;
    pr_trigger_2d.callback = CALLBACK(&Bullet::on_collided);
    pr_trigger_2d.size = Trigger2D::size(30,30);
    m_direction = direction;
    translate(coordinates.x, coordinates.y-50);
    c_partical_system = component_add<ParticleSystem>(pr_partical_system);
    m_speed = speed;
    m_c_trigger_2d = component_add<Trigger2D>(pr_trigger_2d);
    set_tag("bullet");
}

void Bullet::on_update(float dt){
    m_timer += dt;
    if (m_timer > 2) {
        destroy();
    }
    translate(dt*m_direction.x*m_speed, dt*m_direction.y*m_speed);
}

void Bullet::on_collided(Trigger2D other){
    printf("Bullet: collided!\n");
    if(other.owner()->tag() == "generator"){
        printf("Bullet: collided with generator!\n");
    }
}
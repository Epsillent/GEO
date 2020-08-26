#include "entities/bullet.hpp"
#include "components/particle_system.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"
Bullet::Bullet(Side side, const sf::Vector2f &translation, ParticleSystemProperties &pr_partical_system):
    m_translation(translation),
    m_side(side),
    m_timer(0)
{
    c_partical_system = component_add<ParticleSystem>(pr_partical_system);
    
    Trigger2DProperties pr_trigger_2d;
    pr_trigger_2d.callback = CALLBACK(&Bullet::on_collided);
    pr_trigger_2d.size = Trigger2D::size(30, 30);
    m_c_trigger_2d = component_add<Trigger2D>(pr_trigger_2d);
    set_tag("bullet");
}

void Bullet::on_update(float dt) {
    m_timer += dt;
    if (m_timer >= GeoPropeties::bullet_lifetime) {
        destroy();
    }
    translate(m_translation*dt);
}

void Bullet::on_collided(Trigger2D other) {
    if(m_side != static_cast<Entity*>( other.owner() )->m_side && other.owner()->tag() != "bullet" ) {
        destroy();
        Info("Destoryed");
    }
}

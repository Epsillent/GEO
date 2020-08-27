#include "entities/shooter.hpp"
#include "entities/bullet.hpp"
#include "components/sprite_2d.hpp"
#include "const.hpp"
#include <cmath>

Shooter::Shooter(uint8 &cell, Side side): 
    Entity(GeoPropeties::shooter_health,cell,side),
    timer(GeoPropeties::shooter_rate/2.f)
{
    m_body = component_add<Sprite2D>();
    m_body->set_texture(&GeoPropeties::texture_pack->shooter[side]);
    m_body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    
    bullet_partical_sys_pr.color_begin = sf::Color::Red;
    bullet_partical_sys_pr.color_end = sf::Color::Yellow;
    bullet_partical_sys_pr.size = sf::Vector2f(10,10);
    bullet_partical_sys_pr.dispersion = sf::Vector2i(10,10);
    bullet_partical_sys_pr.spawn_rate = 0.00001;

    set_tag("shooter");
}

void Shooter::on_update(float dt) {
    timer += dt;
    if(timer >= GeoPropeties::shooter_rate) {
        object_introduce(new Bullet(m_side,sf::Vector2f(GeoPropeties::bullet_speed*std::pow(-1.f,m_side+2),0),bullet_partical_sys_pr))->translate(GeoPropeties::figure_edge/2,GeoPropeties::figure_edge/2);        
        timer -= GeoPropeties::shooter_rate;
    }
}
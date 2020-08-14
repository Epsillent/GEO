#include "entities/shooter.hpp"
#include "entities/bullet.hpp"
#include "components/sprite_2d.hpp"
#include "const.hpp"

Shooter::Shooter(sf::Vector2f coordinates, sf::Vector2f direction): Entity(GeoPropeties::shooter_health){
    translate(coordinates);
    m_body = component_add<Sprite2D>();
    m_body->set_color(sf::Color::Blue);
    m_body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    
    bullet_partical_sys_pr.color_begin = sf::Color::Red;
    bullet_partical_sys_pr.color_end = sf::Color::Yellow;
    bullet_partical_sys_pr.size = sf::Vector2f(10,10);
    bullet_partical_sys_pr.dispersion = sf::Vector2i(10,10);
    bullet_partical_sys_pr.spawn_rate = 0.00001;

    m_coordinates = coordinates;
    m_direction = direction;
    set_tag("shooter");
}

void Shooter::on_update(float dt) {
    timer += dt;
    float speed = 200;
    if(timer > 3){
        Bullet *bullet = new Bullet(m_direction, sf::Vector2f(100,50), bullet_speed, bullet_partical_sys_pr);       
        object_introduce(bullet);        
        timer -= 3;
    }
}
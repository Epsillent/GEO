#include "entities/shooter.hpp"
#include "entities/bullet.hpp"
#include "components/sprite_2d.hpp"

Shooter::Shooter(sf::Vector2f coordinates){
    translate(coordinates);
    m_body = component_add<Sprite2D>();
    m_body->set_color(sf::Color::Blue);
    m_body->set_size(sf::Vector2f(100,100));
    
    bullet_partical_sys_pr.color_begin = sf::Color::Red;
    bullet_partical_sys_pr.color_end = sf::Color::Yellow;
    bullet_partical_sys_pr.size = sf::Vector2f(10,10);
    bullet_partical_sys_pr.dispersion = sf::Vector2i(10,10);
    bullet_partical_sys_pr.spawn_rate = 0.00001;

    m_coordinates = coordinates;
}

void Shooter::on_update(float dt) {
    timer += dt;
    if(timer > 3){
        sf::Vector2f bullet_direction(1, 0);
        Bullet *bullet = new Bullet(bullet_direction, m_coordinates, bullet_speed, bullet_partical_sys_pr);       
        object_introduce(bullet);        
        timer -= 3;
    }
}
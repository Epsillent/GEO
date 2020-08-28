#include "entities/shooter.hpp"
#include "entities/bullet.hpp"
#include "components/sprite_2d.hpp"
#include "const.hpp"
#include <cmath>


void Shooter::on_introduce(){
    Entity::on_introduce();
    decrease_owner_resources(GeoPropeties::shooter_price);
    m_health = GeoPropeties::shooter_health;
    timer = GeoPropeties::shooter_rate/2.f;

    m_body = component_add<Sprite2D>();
    m_body->set_texture(&GeoPropeties::texture_pack->shooter[m_side]);
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

void Shooter::on_network_translate(const sf::Vector2f &position){
    //Info("RemoteBase:OnTranslate: " + ARG_VEC("LocalPosition",position) + ARG_VEC("SetPosition",sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y)));
    set_local_position(sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::figure_edge,position.y));
    //set_local_position(position);
}
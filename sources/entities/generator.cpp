#include "entities/generator.hpp"
#include "entities/resources.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"
#include "utils/debug.hpp"
#include "scenes/battlefield.hpp"


void Generator::on_introduce(){
    Entity::on_introduce();
    decrease_owner_resources(GeoPropeties::generator_price);

    m_health = GeoPropeties::generator_health;
    timer = 0;
    body = component_add<Sprite2D>();
    body->set_texture(&GeoPropeties::texture_pack->generator[m_side]);
    body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    
    set_tag("generator");
}

void Generator::on_update(float dt) {
    timer+=dt;
    if(timer > GeoPropeties::generator_rate) {
        increase_owner_resources(GeoPropeties::generator_gives);
        timer -= GeoPropeties::generator_rate;
    }
}

void Generator::on_network_translate(const sf::Vector2f &position){
    //Info("RemoteBase:OnTranslate: " + ARG_VEC("LocalPosition",position) + ARG_VEC("SetPosition",sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y)));
    set_local_position(sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::figure_edge,position.y));
    //set_local_position(position);
}
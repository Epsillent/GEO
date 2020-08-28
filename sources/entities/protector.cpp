#include "entities/protector.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"


void Protector::on_introduce(){
    Entity::on_introduce();
    decrease_owner_resources(GeoPropeties::protector_price);
    m_health = GeoPropeties::protector_health;
    m_c_body = component_add<Sprite2D>();
    m_c_body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    
    m_c_body->set_texture(&GeoPropeties::texture_pack->protector[m_side]);

    set_tag("protector");
}

void Protector::on_network_translate(const sf::Vector2f &position){
    //Info("RemoteBase:OnTranslate: " + ARG_VEC("LocalPosition",position) + ARG_VEC("SetPosition",sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y)));
    set_local_position(sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::figure_edge,position.y));
    //set_local_position(position);
}
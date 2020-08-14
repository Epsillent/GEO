#include "entities/base.hpp"
#include "const.hpp"

Base::Base(): Entity(GeoPropeties::base_health){
    m_body = component_add<Sprite2D>();
    m_body->set_color(sf::Color::White);
    m_body->set_size(GeoPropeties::base_height,GeoPropeties::base_width);
}

void Base::on_update(float dt){
    
}
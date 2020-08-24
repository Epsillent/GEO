#include "entities/base.hpp"
#include "const.hpp"

Base::Base(sf::Vector2f coordinates, TextView *health_text_view_to_update, Side side): Entity(GeoPropeties::base_health){
    translate(coordinates);
    m_body = component_add<Sprite2D>();
    m_body->set_color(sf::Color::White);
    m_body->set_size(GeoPropeties::base_width, GeoPropeties::base_height);
    m_body->set_texture(&GeoPropeties::texture_pack->base[side]);
    health_text_view_to_update->set_string( std::to_string(this->m_health) );

    m_health_text_view = health_text_view_to_update;
    add_health_text_view(health_text_view_to_update);
    set_collider_size(sf::Vector2f(GeoPropeties::base_width, GeoPropeties::base_height) );
    m_side = side;
    set_tag("base");
}

void Base::on_update(float dt) {
    
}

void Base::health_decrease(int value) {
    this->m_health-=value;
    m_health_text_view->set_string( std::to_string(this->m_health) );
    if(m_health<=0) {
        m_health_text_view->set_string( "dead" );
        printf("\n123\n");
        destroy();
    }
}
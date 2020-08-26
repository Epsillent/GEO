#include "entities/base.hpp"
#include "const.hpp"
#include "scenes/battlefield.hpp"
Base::Base(Side side, TextView *health_text_view_to_update): 
    m_side(side),
    m_health(GeoPropeties::base_health),
    m_health_text_view(health_text_view_to_update)
{
    m_body = component_add<Sprite2D>();
    m_body->set_color(sf::Color::White);
    m_body->set_size(GeoPropeties::base_width, GeoPropeties::base_height);
    m_body->set_texture(&GeoPropeties::texture_pack->base[side]);

    health_text_view_to_update->set_string( std::to_string(this->m_health) );

    Trigger2DProperties props;
    props.size = Trigger2D::size(GeoPropeties::base_width, GeoPropeties::base_height);
    props.callback = CALLBACK(&Base::on_collided);
    m_c_trigger_2d = component_add<Trigger2D>(props);
    
    set_tag("base");
}

void Base::on_update(float dt) {
    
}

void Base::health_decrease(int value) {
    m_health-=value;
    m_health_text_view->set_string( std::to_string(m_health) );

    if(m_health<=0) {
        m_health_text_view->set_string( "dead" );
        destroy();
        ((Battlefield*)scene())->end_game(m_side);
    }
}
void Base::on_collided(Trigger2D other) {
    if( other.owner()->tag() == "bullet" && m_side != static_cast<Entity*>( other.owner() )->m_side ) {
        health_decrease(1);
        printf("health of this object is %i\n", m_health);
    } 
}

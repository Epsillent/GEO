#include "entities/base.hpp"
#include "const.hpp"
#include "scenes/battlefield.hpp"


Base::Base(){
    
}

void Base::on_introduce(){
    if(type()==NetworkObject::Type::Originator){
        m_side = Side::Left;
        m_health_text_view = ((Battlefield*)scene())->ui_controller->left_health_text_view;
    }else{
        m_side = Side::Right;
        m_health_text_view = ((Battlefield*)scene())->ui_controller->right_health_text_view;
    }
    m_health = GeoPropeties::base_health;
    m_health_text_view->set_string( std::to_string(m_health) );

    m_body = component_add<Sprite2D>();
    m_body->set_color(sf::Color::White);
    m_body->set_size(GeoPropeties::base_width, GeoPropeties::base_height);
    m_body->set_texture(&GeoPropeties::texture_pack->base[m_side]);

    Trigger2DProperties props;
    props.size = Trigger2D::size(GeoPropeties::base_width, GeoPropeties::base_height);
    props.callback = CALLBACK(&Base::on_collided);
    m_c_trigger_2d = component_add<Trigger2D>(props);


    set_tag("base");

}
void Base::on_update(float dt) {
    
}

void Base::health_decrease(int value) {
    if(type()==NetworkObject::Type::Originator){
        uint16 v = (uint16)value;
        originator_event(OriginatorEvent(v));
    }
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
void Base::on_network_translate(const sf::Vector2f &position){
    //Info("RemoteBase:OnTranslate: " + ARG_VEC("LocalPosition",position) + ARG_VEC("SetPosition",sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::selector_size.x,position.y)));
    set_local_position(sf::Vector2f(DisplayServer::window_size().x-position.x-GeoPropeties::base_width,position.y));
    //set_local_position(position);
}
void Base::on_originator_event(const OriginatorEvent &e){
    health_decrease(e.event_code);
}
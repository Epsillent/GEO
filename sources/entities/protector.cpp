#include "entities/protector.hpp"
#include "components/trigger_2d.hpp"
<<<<<<< HEAD
#include "const.hpp"

Protector::Protector(sf::Vector2f coordinates): Entity(GeoPropeties::protector_health) {
=======

Protector::Protector(sf::Vector2f coordinates) {
>>>>>>> caa5cfcb25579d0f43ab3beb76f58f7cbaf74bc9
    Trigger2DProperties pr_trigger_2d;
    //pr_trigger_2d.size(sf::Vector2f(100,100) );
    m_c_trigger_2d = component_add<Trigger2D>();
    m_c_body = component_add<Sprite2D>();
    translate(coordinates);
<<<<<<< HEAD
    m_c_body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    m_c_body->set_color(sf::Color::Yellow);
    set_tag("protector");
=======
    m_c_body->set_size(sf::Vector2f(100,100));
    m_c_body->set_color(sf::Color::Yellow);
>>>>>>> caa5cfcb25579d0f43ab3beb76f58f7cbaf74bc9
}

void Protector::health_decrease(int count){
    m_health-=count;
}
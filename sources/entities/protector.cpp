#include "entities/protector.hpp"
#include "components/trigger_2d.hpp"

Protector::Protector(sf::Vector2f coordinates) {
    Trigger2DProperties pr_trigger_2d;
    //pr_trigger_2d.size(sf::Vector2f(100,100) );
    m_c_trigger_2d = component_add<Trigger2D>();
    m_c_body = component_add<Sprite2D>();
    translate(coordinates);
    m_c_body->set_size(sf::Vector2f(100,100));
    m_c_body->set_color(sf::Color::Yellow);
}

void Protector::health_decrease(int count){
    m_health-=count;
}
#include "entities/protector.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"

Protector::Protector(sf::Vector2f coordinates, Side side): Entity(GeoPropeties::protector_health) {
    translate(coordinates);
    m_c_body = component_add<Sprite2D>();
    m_c_body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    m_c_body->set_color(sf::Color::Yellow);
    this->m_side = side;
    set_tag("protector");
}
#include "entities/protector.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"

Protector::Protector(uint8 &cell, Side side): 
    Entity(GeoPropeties::protector_health,cell,side) 
{
    m_c_body = component_add<Sprite2D>();
    m_c_body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    
    m_c_body->set_texture(&GeoPropeties::texture_pack->protector[side]);

    set_tag("protector");
}
#include "entities/generator.hpp"
#include "entities/resources.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"
#include "utils/debug.hpp"

Generator::Generator(uint8 &cell, Side side,Resources* resources_to_update): 
    Entity(GeoPropeties::generator_health,cell,side),
    m_give(GeoPropeties::generator_gives),
    m_resources_to_update(resources_to_update)
{
    body = component_add<Sprite2D>();
    body->set_texture(&GeoPropeties::texture_pack->generator[side]);
    body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    
    set_tag("generator");
}   

void Generator::on_update(float dt) {
    timer+=dt;
    if(timer > GeoPropeties::generator_rate) {
        m_resources_to_update->resources_increase(m_give);
        timer -= GeoPropeties::generator_rate;
    }
}

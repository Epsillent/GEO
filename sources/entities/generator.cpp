#include "entities/generator.hpp"
#include "entities/resources.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"
#include "utils/debug.hpp"

Generator::Generator(float spawn_rate, Resources* resources_to_update, sf::Vector2f coordinates, Side side): Entity(GeoPropeties::generator_health)
{
    m_side = side;
    translate(sf::Vector2f(coordinates));
    m_spawn_rate = spawn_rate;
    body = component_add<Sprite2D>();
    //body->set_color(sf::Color::Green);
    body->set_texture(&GeoPropeties::texture_pack->generator[side]);
    body->set_size(sf::Vector2f(GeoPropeties::figure_edge, GeoPropeties::figure_edge));
    m_resources_to_update = resources_to_update;
    set_tag("generator");
}   

void Generator::on_update(float dt) {
    timer+=dt;
    if(timer > 2) {
        m_resources_to_update->resources_increase(m_spawn_rate);
        timer -= 2;
    }
}

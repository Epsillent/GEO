#include "entities/generator.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"
#include "utils/debug.hpp"

Generator::Generator(float spawn_rate): Entity(GeoPropeties::generator_health) {
    m_spawn_rate = spawn_rate;
    body = component_add<Sprite2D>();
    body->set_color(sf::Color::Green);
    body->set_size(sf::Vector2f(100,100));
}   
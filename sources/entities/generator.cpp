#include "entities/generator.hpp"
#include "entities/resources.hpp"
#include "components/sprite_2d.hpp"
#include "components/trigger_2d.hpp"
#include "const.hpp"
#include "utils/debug.hpp"

Generator::Generator(float spawn_rate, Resources* resources_to_update, sf::Vector2f coordinates): Entity(GeoPropeties::generator_health) {
    m_spawn_rate = spawn_rate;
    body = component_add<Sprite2D>();
    body->set_color(sf::Color::Green);
    body->set_size(sf::Vector2f(100,100));
    body->set_position(coordinates);
    m_resources_to_update = resources_to_update;
}   

void Generator::on_update(float dt) {
    timer+=dt;
    printf("timer in generator is %f \n", timer);
    if(timer > 2) {
        printf("pam pam\n");
        m_resources_to_update->resources_increase(m_spawn_rate);
        timer -= 3;
    }
}

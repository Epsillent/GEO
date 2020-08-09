#include "scenes/battlefield.hpp"
#include "entities/generator.hpp"
#include "entities/shooter.hpp"
#include "entities/resources.hpp"
#include "engine.hpp"

void Battlefield::on_init() {
    //Resources *left_player_resources = new Resources();
    //Resources *right_layar_resources = new Resources();
    //object_introduce(new Generator(5, left_player_resources));
    object_introduce(new Shooter(sf::Vector2f(100, 100)));
}

void Battlefield::on_update(float dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        Engine::get_singleton()->stop();    
    }
}
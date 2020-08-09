#include "scenes/battlefield.hpp"
#include "entities/generator.hpp"
#include "entities/shooter.hpp"
#include "entities/resources.hpp"
#include "engine.hpp"
#include "scenes/resourcesViewController.hpp"

void Battlefield::on_init() {
    ResourcesViewController *resources_view_controller = new ResourcesViewController();
    object_introduce(new Shooter(sf::Vector2f(100, 100)) );
    
    Engine::get_singleton()->set_ui_controller(resources_view_controller);
    Resources *left_resources = new Resources(resources_view_controller->left_resources);

    object_introduce(new Generator(1, left_resources, sf::Vector2f(300,300)) );
    object_introduce(new Generator(1, left_resources, sf::Vector2f(600,300)) );
}

void Battlefield::on_update(float dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        Engine::get_singleton()->stop();    
    }
}
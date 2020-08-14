#include "scenes/battlefield.hpp"
#include "entities/generator.hpp"
#include "entities/shooter.hpp"
#include "entities/protector.hpp"
#include "entities/resources.hpp"
#include "entities/selector/left_selector.hpp"
#include "entities/selector/right_selector.hpp"

#include "engine.hpp"
#include "scenes/resourcesViewController.hpp"

void Battlefield::on_init() {
    ResourcesViewController *resources_view_controller = new ResourcesViewController();
    Engine::get_singleton()->set_ui_controller(resources_view_controller);
<<<<<<< HEAD
   
    Resources *left_resources = new Resources(resources_view_controller->left_resources_text_view);
    Resources *right_resources = new Resources(resources_view_controller->right_resources_text_view);
   
    object_introduce(new LeftSelector());
    object_introduce(new RightSelector());
    object_introduce(new Shooter(sf::Vector2f(100, 100), sf::Vector2f(1,  0)) );
    object_introduce(new Generator(1, left_resources, sf::Vector2f(800, 100)) );
    object_introduce(new Protector(sf::Vector2f(500, 100)));
=======
    Resources *left_resources = new Resources(resources_view_controller->left_resources);
    Resources *right_resources = new Resources(resources_view_controller->right_resources);

    //object_introduce(new Generator(1, left_resources, sf::Vector2f(300, 300)) );
    object_introduce(new Generator(1, left_resources, sf::Vector2f(600, 100)) );
    //object_introduce(new Protector(sf::Vector2f(800,600)));
>>>>>>> caa5cfcb25579d0f43ab3beb76f58f7cbaf74bc9
}

void Battlefield::on_update(float dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        Engine::get_singleton()->stop();    
    }
}
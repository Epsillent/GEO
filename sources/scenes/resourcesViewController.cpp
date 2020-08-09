#include "scenes/resourcesViewController.hpp"
#include "utils/assets_manager.hpp"
#include "ui/ui.hpp"
#include "ui/ui_controller.hpp"

ResourcesViewController::ResourcesViewController(){
    left_resources = new TextView("1", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 100);
    right_resources = new TextView("2", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 100);
    left_resources->set_position(sf::Vector2f(200, 600));
    right_resources->set_position(sf::Vector2f(1000, 600));
    root.push_back(left_resources);
    root.push_back(right_resources);
}
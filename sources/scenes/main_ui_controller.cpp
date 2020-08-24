#include "scenes/main_ui_controller.hpp"
#include "utils/assets_manager.hpp"
#include "ui/ui.hpp"
#include "ui/ui_controller.hpp"
#include "servers/display_server.hpp"

MainUIController::MainUIController() { 
    left_resources_text_view = new TextView("1", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 60);
    right_resources_text_view = new TextView("2", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 60);

    left_health_text_view  = new TextView( "4", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 80 );
    right_health_text_view = new TextView( "3", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 80 );
    
    right_resources_text_view->set_position(sf::Vector2f(DisplayServer::window_size().x/2+175, 0));
    left_resources_text_view->set_position(sf::Vector2f(410, 0));
    
    left_health_text_view->set_position(sf::Vector2f(20, DisplayServer::window_size().y-100 ));
    right_health_text_view->set_position(sf::Vector2f(DisplayServer::window_size().x-80, DisplayServer::window_size().y-100)) ;

    root.push_back(left_resources_text_view);
    root.push_back(right_resources_text_view);
    root.push_back(left_health_text_view);
    root.push_back(right_health_text_view);
}
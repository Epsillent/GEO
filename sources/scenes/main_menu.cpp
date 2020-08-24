#include "scenes/main_menu.hpp"
#include "ui/ui.hpp"
#include <thread>
#include "server.hpp"
void MainMenu::on_introduce(){
    set_ui_controller(new MainMenuController);
}
void MainMenu::on_update(float dt){

}


MainMenuController::MainMenuController(){
    sf::Vector2f btn_size(200,200);
    float button_padding = 400;
    local_host = new Button(btn_size,sf::Color::Blue);
    local_host->set_text("LocalHost",AssetsManager::get_font("resources/mont.otf"),sf::Color::White);
    local_host->set_position(sf::Vector2f(button_padding,200));
    local_host->set_callback([](){
        std::thread serv(&launch_server,25565);
        serv.detach();
        //TODO autoconnect to a local server
        SceneManager::introduce_scene("Battlefield",new Battlefield,true);
    });

    remote_host = new Button(btn_size,sf::Color::Blue);
    remote_host->set_text("RemoteHost",AssetsManager::get_font("resources/mont.otf"),sf::Color::White);
    remote_host->set_position(sf::Vector2f(DisplayServer::window_size().x-btn_size.x-button_padding,200));
    remote_host->set_callback([](){
        SceneManager::introduce_scene("Battlefield",new Battlefield,true);
    });
    root.push_back(local_host);
    root.push_back(remote_host);
}






#include "scenes/main_menu.hpp"
#include "ui/ui.hpp"
#include "const.hpp"
#include <thread>
#include "server.hpp"

class MenuBackground: public GameObject{
public:
    MenuBackground() {
        Sprite2D *sprite = component_add<Sprite2D>();
        sprite->set_size(DisplayServer::window_size().x,DisplayServer::window_size().y);
        sprite->set_texture(&GeoPropeties::texture_pack->main_menu_background);
    }
};

void MainMenu::on_introduce(){
    object_introduce(new MenuBackground);
    set_ui_controller(new MainMenuController);
}
void MainMenu::on_update(float dt){

}


MainMenuController::MainMenuController(){
    sf::Vector2f btn_size(300,300);
    float button_padding = 300;
    local_host = new Button(btn_size,sf::Color::White);
    local_host->set_position(sf::Vector2f(button_padding,200));
    local_host->set_texture(&GeoPropeties::texture_pack->local_btn);
    local_host->set_callback([](){
        if(!server){
            server = new GeoServer(25565);
            std::thread serv(&launch_server);
            serv.detach();
        }
        SceneManager::introduce_scene("Battlefield",new Battlefield(Host(sf::IpAddress::getLocalAddress(),25565)),true);
    });

    remote_host = new Button(btn_size,sf::Color::White);
    remote_host->set_position(sf::Vector2f(DisplayServer::window_size().x-btn_size.x-button_padding,200));
    remote_host->set_texture(&GeoPropeties::texture_pack->remote_btn);
    remote_host->set_callback([](){
        SceneManager::introduce_scene("Battlefield",new Battlefield,true);
    });
    root.push_back(local_host);
    root.push_back(remote_host);
}






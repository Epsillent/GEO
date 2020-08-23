#include "scenes/battlefield.hpp"
#include "entities/generator.hpp"
#include "entities/shooter.hpp"
#include "entities/protector.hpp"
#include "entities/resources.hpp"
#include "entities/selector/selector.hpp"
#include "scenes/main_ui_controller.hpp"
#include "entities/base.hpp"
#include "string.h"
#include "engine.hpp"
#include "servers/display_server.hpp"
#include "const.hpp"
#include "core/math/random.hpp"
bool Battlefield::started = false;

Background::Background(){
    Sprite2D *sprite = component_add<Sprite2D>();
    sprite->set_size(DisplayServer::window_size().x,DisplayServer::window_size().y);
    sprite->set_texture(&GeoPropeties::texture_pack->battlefield);
}

void Battlefield::on_introduce() {
    sf::Clock time;
    memset(field,0,sizeof(field));
    std::cout << "Enter server ip:";
    std::string ip;
    std::cin >> ip;
    std::cout << "Enter server port:";
    uint16 port;
    std::cin >> port;
    connect(Host(ip,port));
    
    GeoPropeties::texture_pack = new TexturePack("resources/capitalist/");
    object_introduce(new Background());

    MainUIController *main_ui_controller = new MainUIController();
    set_ui_controller( main_ui_controller );
   
    m_left_resources = (Resources*)object_introduce(new Resources(main_ui_controller->left_resources_text_view));
    m_right_resources = (Resources*)object_introduce(new Resources(main_ui_controller->right_resources_text_view));

    m_left_resources->resources_increase(1000);
    m_right_resources->resources_increase(1000);
    Random::seed(time.getElapsedTime().asMicroseconds());
    LocalSelector *sel = new LocalSelector;
    sel->translate(GeoPropeties::grid_offset);
    network_object_introduce(sel);

    Info("Waiting for opponent to connect...");
    while(!started){
        fetch();
    }
    Info("Game started");

    //object_introduce(new Base(sf::Vector2f(DisplayServer::window_size().x-150, DisplayServer::window_size().y/2-160), main_ui_controller->left_health_text_view, Side::Right ) );   
    //object_introduce( new Base(  sf::Vector2f(30,DisplayServer::window_size().y/2-160) , main_ui_controller->right_health_text_view , Side::Left  )  );
}

void Battlefield::on_update(float dt) {
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        Engine::get_singleton()->stop();    
    }

}
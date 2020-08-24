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
#include "server.hpp"
// REMOVE THIS IN REALESE BUILD
#define TEST

#ifndef TEST
bool Battlefield::started = false;
#else
bool Battlefield::started = true;
#endif
Background::Background() {
    Sprite2D *sprite = component_add<Sprite2D>();
    sprite->set_size(DisplayServer::window_size().x,DisplayServer::window_size().y);
    sprite->set_texture(&GeoPropeties::texture_pack->battlefield);
}

Battlefield::Battlefield():
    autoconnect(false)
{}

Battlefield::Battlefield(const Host &host):
    autoconnect(true),
    localhost(host)
{

}
void Battlefield::on_introduce() {
    sf::Clock time;
    memset(field,0,sizeof(field));
    if(autoconnect){
        while(!server_started)
        {
            ;
        }
        connect(localhost);
    }else{
        std::cout << "Enter server ip:";
        std::string ip;
        std::cin >> ip;
        std::cout << "Enter server port:";
        uint16 port;
        std::cin >> port;
        connect(Host(ip,port));
    }
    object_introduce(new Background());

    MainUIController *main_ui_controller = new MainUIController();
    set_ui_controller( main_ui_controller );
   
    m_right_resources = new Resources(main_ui_controller->right_resources_text_view);
    m_left_resources = new Resources(main_ui_controller->left_resources_text_view);

    m_left_resources->resources_increase(3);
    m_right_resources->resources_increase(3);

    object_introduce( new Shooter(sf::Vector2f(600,200), sf::Vector2f(-1,0), Side::Right) );                

    object_introduce( new Base(sf::Vector2f(0, 165), main_ui_controller->left_health_text_view , Side::Left ));                
    object_introduce( new Base(sf::Vector2f(0, 265), main_ui_controller->left_health_text_view , Side::Left ));            
    object_introduce( new Base(sf::Vector2f(0, 365), main_ui_controller->left_health_text_view , Side::Left ));  

    object_introduce( new Base(sf::Vector2f(DisplayServer::window_size().x-100, 165), main_ui_controller->right_health_text_view , Side::Right ));                
    object_introduce( new Base(sf::Vector2f(DisplayServer::window_size().x-100, 265), main_ui_controller->right_health_text_view , Side::Right ));            
    object_introduce( new Base(sf::Vector2f(DisplayServer::window_size().x-100, 365), main_ui_controller->right_health_text_view , Side::Right ));             

    Random::seed(time.getElapsedTime().asMicroseconds());
    LocalSelector *sel = new LocalSelector;
    sel->translate(GeoPropeties::grid_offset);
    network_object_introduce(sel);

    Info("Waiting for opponent to connect...");
    while(!started){
        if(!autoconnect)
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
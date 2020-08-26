#include "scenes/battlefield.hpp"
#include "entities/generator.hpp"
#include "entities/shooter.hpp"
#include "entities/protector.hpp"
#include "entities/resources.hpp"
#include "entities/selector/selector.hpp"
#include "entities/base.hpp"
#include "string.h"
#include "engine.hpp"
#include "servers/display_server.hpp"
#include "const.hpp"
#include "core/math/random.hpp"
#include "server.hpp"
// REMOVE THIS IN REALESE BUILD
//#define TEST


LocalSelector *Battlefield::local_selector = nullptr;
RemoteSelector *Battlefield::remote_selector = nullptr;

BattlefieldUIController::BattlefieldUIController() { 
    left_resources_text_view = new TextView("1", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 60);
    right_resources_text_view = new TextView("2", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 60);

    left_health_text_view  = new TextView( "4", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 80 );
    right_health_text_view = new TextView( "3", AssetsManager::get_font("resources/mont.otf"), sf::Color::White, 80 );
    
    right_resources_text_view->set_position(sf::Vector2f(DisplayServer::window_size().x/2+175, 0));
    left_resources_text_view->set_position(sf::Vector2f(410, 0));
    
    left_health_text_view->set_position(sf::Vector2f(20, DisplayServer::window_size().y-100 ));
    right_health_text_view->set_position(sf::Vector2f(DisplayServer::window_size().x-80, DisplayServer::window_size().y-100)) ;
    sf::Vector2f btn_size(100,100);
    Button *main_menu = new Button(btn_size);
    main_menu->set_position(sf::Vector2f(DisplayServer::window_size().x/2-btn_size.x/2,5));
    main_menu->set_texture(&GeoPropeties::texture_pack->main_menu_button);
    main_menu->set_callback([](){
        SceneManager::set_scene("MainMenu");
        SceneManager::substract_scene("Battlefield");
    });
    root.push_back(left_resources_text_view);
    root.push_back(right_resources_text_view);
    root.push_back(left_health_text_view);
    root.push_back(right_health_text_view);
    
    root.push_back(main_menu);

}

void BattlefieldUIController::end_game(Side side){
    sf::Vector2f banner_size(1000,600);
    ImageView *banner = new ImageView(banner_size);
    if(side == Side::Left){
        banner->set_texture(&GeoPropeties::texture_pack->lose_notification);
    }else{
        banner->set_texture(&GeoPropeties::texture_pack->win_notification);
    }
    banner->set_position(sf::Vector2f(DisplayServer::window_size().x/2-banner_size.x/2,100));
    
    sf::Vector2f btn_size(100,100);
    Button *btn = new Button(sf::Vector2f(100,100));
    btn->set_texture(&GeoPropeties::texture_pack->main_menu_button);
    btn->set_position(sf::Vector2f(DisplayServer::window_size().x/2-btn_size.x/2,200));
    btn->set_callback([](){
        SceneManager::set_scene("MainMenu");
        SceneManager::substract_scene("Battlefield");
    });
    delete *std::prev(root.end());
    root.pop_back();
    root.push_back(banner);
    root.push_back(btn);

}


Background::Background() {
    Sprite2D *sprite = component_add<Sprite2D>();
    sprite->set_size(DisplayServer::window_size().x,DisplayServer::window_size().y);
    sprite->set_texture(&GeoPropeties::texture_pack->battlefield);
}

Battlefield::Battlefield():
    autoconnect(false),
    game_finished(false)
{
    local_selector = nullptr;
    remote_selector = nullptr;
}

Battlefield::Battlefield(const Host &host):
    autoconnect(true),
    localhost(host)
{
    local_selector = nullptr;
    remote_selector = nullptr;
}
void Battlefield::on_introduce() {
    sf::Clock time;
    memset(field,0,sizeof(field));
    if(autoconnect){
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

    ui_controller = new BattlefieldUIController();
    set_ui_controller( ui_controller );
   
    m_right_resources = new Resources(ui_controller->right_resources_text_view);
    m_left_resources = new Resources(ui_controller->left_resources_text_view);

    m_left_resources->resources_increase(3);
    m_right_resources->resources_increase(3);            

    object_introduce( new Base(Side::Left, ui_controller->left_health_text_view))->translate(sf::Vector2f(0, 165));
    object_introduce( new Base(Side::Left, ui_controller->left_health_text_view))->translate(sf::Vector2f(0, 265));    
    object_introduce( new Base(Side::Left, ui_controller->left_health_text_view))->translate(sf::Vector2f(0, 365));    

    object_introduce( new Base(Side::Right, ui_controller->right_health_text_view))->translate(sf::Vector2f(DisplayServer::window_size().x-100, 165));                
    object_introduce( new Base(Side::Right, ui_controller->right_health_text_view))->translate(sf::Vector2f(DisplayServer::window_size().x-100, 265));                
    object_introduce( new Base(Side::Right, ui_controller->right_health_text_view))->translate(sf::Vector2f(DisplayServer::window_size().x-100, 365));                
          

    Random::seed(time.getElapsedTime().asMicroseconds());
    local_selector = new LocalSelector(&field);
    local_selector->translate(GeoPropeties::grid_offset);
    network_object_introduce(local_selector);

    Info("Waiting for opponent to connect...");
    while(!local_selector && !remote_selector){
        fetch();
    }
    begin_game();
    //object_introduce(new Base(sf::Vector2f(DisplayServer::window_size().x-150, DisplayServer::window_size().y/2-160), main_ui_controller->left_health_text_view, Side::Right ) );   
    //object_introduce( new Base(  sf::Vector2f(30,DisplayServer::window_size().y/2-160) , main_ui_controller->right_health_text_view , Side::Left  )  );
}

void Battlefield::on_update(float dt) {
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        Engine::get_singleton()->stop();    
    }

}


void Battlefield::begin_game(){
    Info("Game started");
}
void Battlefield::end_game(Side side){
    if(!game_finished){
        Info("GameFinished");
        game_finished = true;
        ui_controller->end_game(side);
        local_selector->destroy();
        disconnect();
    }
}
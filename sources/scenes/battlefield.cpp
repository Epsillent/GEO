#include "scenes/battlefield.hpp"
#include "entities/generator.hpp"
#include "entities/shooter.hpp"
#include "entities/protector.hpp"
#include "entities/resources.hpp"
#include "entities/selector/left_selector.hpp"
#include "entities/selector/right_selector.hpp"
#include "scenes/main_ui_controller.hpp"
#include "entities/base.hpp"
#include "string.h"
#include "engine.hpp"
#include "servers/display_server.hpp"
#include "const.hpp"

Background::Background(){
    Sprite2D *sprite = component_add<Sprite2D>();
    sprite->set_size(DisplayServer::window_size().x,DisplayServer::window_size().y);
    sprite->set_texture(&GeoPropeties::texture_pack->battlefield);
}

void Battlefield::on_introduce() {
    memset(field,0,sizeof(field));

    GeoPropeties::texture_pack = new TexturePack("resources/capitalist/");
    object_introduce(new Background());

    MainUIController *main_ui_controller = new MainUIController();
    set_ui_controller( main_ui_controller );
   
    Resources *left_resources = new Resources(main_ui_controller->left_resources_text_view);
    Resources *right_resources = new Resources(main_ui_controller->right_resources_text_view);

    left_resources->resources_increase(1000);
    right_resources->resources_increase(1000);



    m_right_selector = new RightSelector();
    m_left_selector = new LeftSelector();

    m_left_resources = left_resources;
    m_right_resources = right_resources;

    object_introduce(m_right_selector);
    object_introduce(m_left_selector);

    object_introduce(new Base(sf::Vector2f(DisplayServer::window_size().x-150, DisplayServer::window_size().y/2-160), main_ui_controller->left_health_text_view, Side::Right ) );   
    object_introduce( new Base(  sf::Vector2f(30,DisplayServer::window_size().y/2-160) , main_ui_controller->right_health_text_view , Side::Left  )  );
}

void Battlefield::on_update(float dt) {
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        Engine::get_singleton()->stop();    
    }

    if(Input::key_pressed(KeyCode::Enter)) {  
        if(m_right_selector->m_figure_trigger == 0 && m_right_resources->get_resources() >= GeoPropeties::generator_price ) {
            if(!is_pressed) {
                is_pressed = true;
                m_right_resources->resources_decrease(GeoPropeties::generator_price);
                object_introduce( new Generator( 1, m_right_resources, m_right_selector->global_position()+GeoPropeties::offset_in_selector, Side::Right ) );
            }
        } else if (m_right_selector->m_figure_trigger == 1 && m_right_resources->get_resources() >= GeoPropeties::generator_price ) {
            if(!is_pressed) {
                object_introduce( new Shooter( m_right_selector->global_position()+GeoPropeties::offset_in_selector , sf::Vector2f(-1,0), Side::Right ) );
                m_right_resources->resources_decrease(GeoPropeties::generator_price);
                is_pressed = true;
            }
        } else if(m_right_selector->m_figure_trigger == 2 && m_right_resources->get_resources() >= GeoPropeties::generator_price ) {
            if(!is_pressed) {
                object_introduce( new Protector( m_right_selector->global_position()+GeoPropeties::offset_in_selector, Side::Right ) );
                m_right_resources->resources_decrease(GeoPropeties::generator_price);
                is_pressed = true;
            }
        } else {
            is_pressed = false;
        }
    } else {
        is_pressed = false;
    }

    if(Input::key_pressed(KeyCode::Space)) {  
        if( m_left_selector->m_figure_trigger == 0 && m_left_resources->get_resources() >= GeoPropeties::generator_price ) {
            if(!is_pressed_left) {
                is_pressed_left = true;
                m_left_resources->resources_decrease(GeoPropeties::generator_price);
                object_introduce( new Generator( 1, m_left_resources, m_left_selector->global_position()+GeoPropeties::offset_in_selector, Side::Left ) );
            }
        } else if (m_left_selector->m_figure_trigger == 1 && m_left_resources->get_resources() >= GeoPropeties::shooter_price ) {
            if(!is_pressed_left) {
                object_introduce( new Shooter( m_left_selector->global_position()+GeoPropeties::offset_in_selector , sf::Vector2f(1,0), Side::Left ) );
                m_left_resources->resources_decrease(GeoPropeties::shooter_price);
                is_pressed_left = true;
            }
        } else if(m_left_selector->m_figure_trigger == 2 && m_left_resources->get_resources() >= GeoPropeties::shooter_price ) {
            if(!is_pressed_left) {
                object_introduce( new Protector( m_left_selector->global_position()+GeoPropeties::offset_in_selector, Side::Left ) );
                m_left_resources->resources_decrease(GeoPropeties::protector_price);
                is_pressed_left = true;
            }
        } else {
            is_pressed_left = false;
        }
    } else {
        is_pressed_left = false;
    }
}
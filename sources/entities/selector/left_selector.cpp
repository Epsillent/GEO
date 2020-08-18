#include "entities/selector/left_selector.hpp"

LeftSelector::LeftSelector(): Selector(sf::Color::Red, sf::Vector2f(120,120), sf::Vector2f(200, 200) ) {

}

void LeftSelector::on_update(float dt) {
    int speed = 100;
    
    if(Input::key_pressed(KeyCode::W)){
        if(!is_mooved){
            is_mooved = true;
            translate(0,-speed);
        } 
    }
    else if(Input::key_pressed(KeyCode::S)){
        if(!is_mooved){
            translate(0,speed);
            is_mooved = true;
        }
    }
    else if(Input::key_pressed(KeyCode::D)){
        if(!is_mooved){
            translate(speed,0);
            is_mooved = true;
        }
    }
    else if(Input::key_pressed(KeyCode::A)){
        if(!is_mooved){
            is_mooved = true;
            translate(-speed,0);      
        }
    } 
    else {
        is_mooved = false ;
    }

    if(Input::key_pressed(KeyCode::R)) { 
        m_figure_trigger = 0;
    } else if(Input::key_pressed(KeyCode::T)) {
        m_figure_trigger = 1;
    } else if(Input::key_pressed(KeyCode::Y)) {
        m_figure_trigger = 2;
    }
}
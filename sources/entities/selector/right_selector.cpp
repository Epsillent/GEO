#include "entities/selector/right_selector.hpp"

RightSelector::RightSelector(): Selector(sf::Color::Blue, sf::Vector2f(120,120), sf::Vector2f(200, 200) ) {

}

void RightSelector::on_update(float dt) {
    int speed = 100;
    
    if(Input::key_pressed(KeyCode::Up)) { 
        if(!is_mooved) {
            is_mooved = true;
            translate(0,-speed);
        } 
    }
    else if(Input::key_pressed(KeyCode::Down)) {
        if(!is_mooved) {
            translate(0,speed);
            is_mooved = true;
        }
    }
    else if(Input::key_pressed(KeyCode::Right)) {
        if(!is_mooved) {
            translate(speed,0);
            is_mooved = true;
        }
    }
    else if(Input::key_pressed(KeyCode::Left)) {
        if(!is_mooved) {
            is_mooved = true;
            translate(-speed,0);      
        }
    } 
    else {
        is_mooved = false ;
    }
}
    
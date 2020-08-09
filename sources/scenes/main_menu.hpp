#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "engine.hpp"
#include "ui/button.hpp"

class MainMenu: public BaseScene {
    private:

    public:
        void on_init();
        void on_update();
};

class MainMenuController: public UIController {
    private:
        //Button *battlefield_button;
    public: 
        MainMenuController(){
            //battlefield_button = new Button(sf::Vector2f(100, 100), sf::Color::Green);
            //battlefield_button->set_callback(std::bind(&MainMenuController::battlefield_button_was_pressed, this));
            //root = battlefield_button;
        }

        void battlefield_button_was_pressed(){
            //printf("battlefield button was pressed!");
        }
};
#endif
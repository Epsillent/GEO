#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "engine.hpp"
#include "ui/button.hpp"
#include "utils/assets_manager.hpp"
#include "scenes/battlefield.hpp"
class MainMenu: public BaseScene {
    private:

    public:
        void on_introduce()override;
        void on_update(float dt)override;
};

class MainMenuController: public UIController {
    private:
        Button *local_host;
        Button *remote_host;
    public: 
        MainMenuController();
};
#endif
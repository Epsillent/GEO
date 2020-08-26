#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "engine.hpp"
#include "ui/ui_controller.hpp"
#include "ui/ui.hpp"
#include "utils/assets_manager.hpp"
#include <vector>
#include "entities/entity.hpp"

#include "entities/resources.hpp"
#include "network/network_scene.hpp"

class BattlefieldUIController: public UIController{       
    public:  
        TextView *left_resources_text_view;
        TextView *right_resources_text_view;
        
        TextView *left_health_text_view;
        TextView *right_health_text_view;
        BattlefieldUIController();

        void end_game(Side loser);
};

class Background: public GameObject{
public:
    Background();
};
class LocalSelector;
class RemoteSelector;

class Battlefield: public NetworkScene {
    private:
        bool autoconnect;
        bool game_finished;
        Host localhost;
        Resources *m_left_resources;
        Resources *m_right_resources;
        static LocalSelector *local_selector;
        static RemoteSelector *remote_selector;
        BattlefieldUIController *ui_controller;
        
        uint8 field[5][5];
        uint8 fantom;
        friend class Selector;
        friend class RemoteSelector;
        friend class LocalSelector;
    public:
        Battlefield();
        Battlefield(const Host &host);
        void on_introduce()override;
        void on_update(float dt)override;
        void begin_game();
        void end_game(Side loser = Side::Left);
};

#endif
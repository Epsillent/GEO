#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "engine.hpp"
#include "ui/ui_controller.hpp"
#include "ui/ui.hpp"
#include "utils/assets_manager.hpp"
#include <vector>

#include "entities/resources.hpp"
#include "network/network_scene.hpp"

class Background: public GameObject{
public:
    Background();
};

class Battlefield: public NetworkScene {
    private:
        static bool started;
        bool autoconnect;
        Host localhost;
        Resources *m_left_resources;
        Resources *m_right_resources;
        
        uint8 field[5][5];
        friend class Selector;
        friend class RemoteSelector;
        friend class LocalSelector;
    public:
        Battlefield();
        Battlefield(const Host &host);
        void on_introduce()override;
        void on_update(float dt)override;
        void erase(const sf::Vector2u &position);
};

#endif
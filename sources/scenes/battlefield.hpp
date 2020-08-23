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
        Resources *m_left_resources;
        Resources *m_right_resources;
        
        uint8 field[5][5];
        friend class Selector;
        friend class RemoteSelector;
        friend class LocalSelector;
    public:
        void on_introduce()override;
        void on_update(float dt)override;
};

#endif
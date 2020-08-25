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
class LocalSelector;
class RemoteSelector;

class Battlefield: public NetworkScene {
    private:
        bool autoconnect;
        Host localhost;
        Resources *m_left_resources;
        Resources *m_right_resources;
        static LocalSelector *local_selector;
        static RemoteSelector *remote_selector;
        
        uint8 field[5][5];
        friend class Selector;
        friend class RemoteSelector;
        friend class LocalSelector;
    public:
        Battlefield();
        Battlefield(const Host &host);
        void on_introduce()override;
        void on_update(float dt)override;
        void begin_game();
        void end_game();
};

#endif
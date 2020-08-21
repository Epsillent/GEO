#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "engine.hpp"
#include "ui/ui_controller.hpp"
#include "ui/ui.hpp"
#include "utils/assets_manager.hpp"
#include <vector>

#include "entities/selector/left_selector.hpp"
#include "entities/selector/right_selector.hpp"
#include "entities/resources.hpp"


class Background: public GameObject{
public:
    Background();
};

class Battlefield: public BaseScene {
    private:
        RightSelector *m_right_selector;
        LeftSelector *m_left_selector;
        bool is_pressed=false;
        bool is_pressed_left=false;
        Resources *m_left_resources;
        Resources *m_right_resources;
        
        uint8 field[5][11];
        friend class Selector;
    public:
        void on_introduce()override;
        void on_update(float dt)override;
};

#endif
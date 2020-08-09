#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "engine.hpp"
#include "ui/ui_controller.hpp"
#include "ui/ui.hpp"
#include "utils/assets_manager.hpp"
#include <vector>

class Battlefield: public BaseScene {
    public:
        void on_init()override;
        void on_update(float dt)override;
};

#endif
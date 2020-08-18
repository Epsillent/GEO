#ifndef RESOURCES_VIEW_CONTROLLER_H
#define RESOURCES_VIEW_CONTROLLER_H

#include "engine.hpp"
#include "ui/ui.hpp"
#include "ui/ui_controller.hpp"

class MainUIController: public UIController{       
    public:  
        TextView *left_resources_text_view;
        TextView *right_resources_text_view;
        
        TextView *left_health_text_view;
        TextView *right_health_text_view;
        MainUIController();
};

#endif
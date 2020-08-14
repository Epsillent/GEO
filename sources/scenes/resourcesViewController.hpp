#ifndef RESOURCES_VIEW_CONTROLLER_H
#define RESOURCES_VIEW_CONTROLLER_H

#include "engine.hpp"
#include "ui/ui.hpp"
#include "ui/ui_controller.hpp"

class ResourcesViewController: public UIController{
    private:
       
    public:  
        TextView *left_resources_text_view;
        TextView *right_resources_text_view;
        ResourcesViewController();
};

#endif
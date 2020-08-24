#ifndef RESOURCES_H
#define RESOURCES_H

#include "engine.hpp"
#include "ui/ui.hpp"
#include "ui/ui_controller.hpp"
#include "utils/assets_manager.hpp"

class Resources: public GameObject {
    public:
        int m_resources_count=0;
        TextView *m_text_view;
        int timer=0;
    public:
        Resources(TextView *text_view);
        void on_update(float dt)override;
        void resources_increase(int count);
        void resources_decrease(int count);
        int get_resources();
};

#endif
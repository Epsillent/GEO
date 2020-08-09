#ifndef RESOURCES_H
#define RESOURCES_H

#include "engine.hpp"

class Resources: public GameObject {
    private:
        int m_resources_count;
    public:
        Resources();
        void on_update(float dt)override;
        void on_init()override;
        void resources_increase(int count);
         int get_resources();
};

#endif
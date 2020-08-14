#ifndef RIGHT_SELECTOR_H
#define RIGHT_SELECTOR_H

#include "engine.hpp"
#include "entities/selector/selector.hpp"


class RightSelector: public Selector {
    private:
        Sprite2D *m_body;
        bool is_mooved;
    public:
        RightSelector();
        void on_update(float dt);
};

#endif
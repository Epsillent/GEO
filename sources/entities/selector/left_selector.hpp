#ifndef LEFT_SELECTOR_H
#define LEFT_SELECTOR_H

#include "engine.hpp"
#include "entities/selector/selector.hpp"


class LeftSelector: public Selector {
    private:
        Sprite2D *m_body;
        bool is_mooved;
    public:
        LeftSelector();
        void on_update(float dt);
};

#endif
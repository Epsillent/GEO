#ifndef BASE_H
#define BASE_H

#include "engine.hpp"
#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"
#include "ui/ui.hpp"

class Base: public Entity {
    private:
        Sprite2D *m_body;
        TextView *m_health_text_view;
    public:
        Base(sf::Vector2f coordinates, TextView *health_text_view_to_update, Side side);
        void on_update(float dt)override;
        void health_decrease(int value);
        void on_destroy()override;
};

#endif
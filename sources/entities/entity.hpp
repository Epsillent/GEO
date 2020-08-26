#ifndef ENTITY_H
#define ENTITY_H

#include "engine.hpp"
#include "components/trigger_2d.hpp"
#include "ui/ui.hpp"
#include "core/typedefs.hpp"

enum Side: uint8 {
    Left = 0,
    Right = 1
};


class Entity: public GameObject {
    private:
        TextView *m_health_text_view=nullptr;
    protected:
        Trigger2D *m_c_trigger_2d;
        int m_health;
        uint8 &m_cell;
        
    public:
        Entity(int health, uint8 &cell, Side side);
        void on_introduce()override;
        Side m_side;
        void make_damage(int damage);
        void on_collided(Trigger2D other);
        void add_health_text_view(TextView *health_text_view);
        void set_collider_size(sf::Vector2f size);
        void on_destroy()override;
};

#endif
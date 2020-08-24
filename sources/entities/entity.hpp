#ifndef ENTITY_H
#define ENTITY_H

#include "engine.hpp"
#include "components/trigger_2d.hpp"
#include "ui/ui.hpp"

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
        
    public:
        Entity(int health);
        Side m_side;
        void make_damage(int damage);
        void on_collided(Trigger2D other);
        void add_health_text_view(TextView *health_text_view);
        void set_collider_size(sf::Vector2f size);
};

#endif
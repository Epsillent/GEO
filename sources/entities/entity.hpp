#ifndef ENTITY_H
#define ENTITY_H

#include "engine.hpp"
#include "components/trigger_2d.hpp"

class Entity: public GameObject {
    private:
        Trigger2D *m_c_trigger_2d;
    protected:
        int m_health;
    public:
        Entity(int health);
        void make_damage(int damage);
        void on_collided(Trigger2D other);
};

#endif
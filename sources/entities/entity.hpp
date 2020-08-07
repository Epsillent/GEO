#ifndef ENTITY_H
#define ENTITY_H

#include "engine.hpp"

class Entity: public GameObject {
    private:
        int m_health;
    public:
        Entity(int health);
        void make_damage(int damage);
};

#endif
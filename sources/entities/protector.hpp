#ifndef PROTECTOR_H
#define PROTECTOR_H

#include "engine.hpp"
#include "components/trigger_2d.hpp"
#include "components/sprite_2d.hpp"
#include "entities/entity.hpp"

<<<<<<< HEAD
class Protector: public Entity {
=======
class Protector: public GameObject {
>>>>>>> caa5cfcb25579d0f43ab3beb76f58f7cbaf74bc9
    private:
        int m_health=5;
        Sprite2D *m_c_body;
        Trigger2D *m_c_trigger_2d;
    public:
        Protector(sf::Vector2f coordinates);
        void health_decrease(int count);
};

#endif
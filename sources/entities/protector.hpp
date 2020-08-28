#ifndef PROTECTOR_H
#define PROTECTOR_H

#include "engine.hpp"
#include "components/trigger_2d.hpp"
#include "components/sprite_2d.hpp"
#include "entities/entity.hpp"

class Protector: public Entity {
    NETWORK_CLASS(Protector, Entity)
    private:
        Sprite2D *m_c_body;
    public:
        Protector() = default;

        void on_introduce()override;
        void on_network_translate(const sf::Vector2f &position)override;
};

#endif
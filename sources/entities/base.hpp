#ifndef BASE_H
#define BASE_H

#include "engine.hpp"
#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"
#include "network/network_object.hpp"
#include "ui/ui.hpp"


class Base: public NetworkObject{
    NETWORK_CLASS(Base,NetworkObject)
private:
    Side m_side;
    int m_health;

    TextView *m_health_text_view;

    Trigger2D *m_c_trigger_2d;
    
    Sprite2D *m_body;
public:
    Base();
    void on_introduce()override;
    void on_update(float dt)override;
    void health_decrease(int value);
    void on_collided(Trigger2D other);

    void on_network_translate(const sf::Vector2f &position)override;

    void on_originator_event(const OriginatorEvent &e)override;
};

#endif
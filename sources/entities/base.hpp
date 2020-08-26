#ifndef BASE_H
#define BASE_H

#include "engine.hpp"
#include "entities/entity.hpp"
#include "components/sprite_2d.hpp"
#include "ui/ui.hpp"

class Base: public GameObject {
private:
    Side m_side;
    int m_health;

    TextView *m_health_text_view;

    Trigger2D *m_c_trigger_2d;
    
    Sprite2D *m_body;
public:
    Base(Side side, TextView *health_text_view_to_update);
    void on_update(float dt)override;
    void health_decrease(int value);
    void on_collided(Trigger2D other);
};

#endif
#ifndef ENTITY_H
#define ENTITY_H

#include "engine.hpp"
#include "components/trigger_2d.hpp"
#include "ui/ui.hpp"
#include "core/typedefs.hpp"
#include "network/network_object.hpp"

enum Side: uint8 {
    Left = 0,
    Right = 1
};


class Entity: public NetworkObject {
    NETWORK_CLASS(Entity,NetworkObject)
    private:
        TextView *m_health_text_view=nullptr;
    protected:
        Trigger2D *m_c_trigger_2d;
        int m_health;
        uint8 *m_cell;
        
    public:
        Entity();
        void on_introduce()override;
        Side m_side;
        void make_damage(int damage);
        void on_collided(Trigger2D other);
        void add_health_text_view(TextView *health_text_view);
        void set_collider_size(sf::Vector2f size);
        void on_destroy()override;

        void decrease_owner_resources(int resources);
        void increase_owner_resources(int resources);

        Entity *bind_cell(uint8 *cell);
};

#endif
#ifndef SELECTOR_H
#define SELECTOR_H
#include "entities/entity.hpp"
#include "engine.hpp"
#include "components/sprite_2d.hpp"
#include "const.hpp"
#include "network/network_object.hpp"

enum EntitiesList : uint16 {
    None,
    GeneratorType,
    ProtectorType,
    ShooterType
};

class LocalSelector: public NetworkObject{
    NETWORK_CLASS(LocalSelector, NetworkObject)
private:
    sf::Vector2u m_current_cell;
    EntitiesList m_selected;
    Sprite2D *mp_body;
    float m_time;
    float m_delay;
    bool spawned;
public:
    LocalSelector();
    void on_introduce()override;
    void on_network_translate(const sf::Vector2f &local_position)override;
    void on_update(float dt)override;
    void move(int x, int y);
};


class RemoteSelector: public NetworkObject{
    NETWORK_CLASS(RemoteSelector, NetworkObject)
private:
    Sprite2D *mp_body;
public:
    void on_introduce()override;
    void on_network_translate(const sf::Vector2f &local_position)override;
    void on_originator_event(const OriginatorEvent &event)override;
    void on_destroy()override;
};

#endif
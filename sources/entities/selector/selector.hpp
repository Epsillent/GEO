#ifndef SELECTOR_H
#define SELECTOR_H
#include "entities/entity.hpp"
#include "engine.hpp"
#include "components/sprite_2d.hpp"

class Selector: public GameObject {
    private:
        Sprite2D *m_body;
    public:
        sf::Vector2f m_coorinates;
        int m_figure_trigger=0;
        Selector(sf::Color color, sf::Vector2f size, sf::Vector2f coordinates, Side side);
        void on_update(float dt);
};

#endif
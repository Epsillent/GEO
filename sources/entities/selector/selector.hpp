#ifndef SELECTOR_H
#define SELECTOR_H

#include "engine.hpp"
#include "components/sprite_2d.hpp"

class Selector: public GameObject {
    private:
        Sprite2D *m_body;
        
    public:
        sf::Vector2f m_coorinates;
        Selector(sf::Color color, sf::Vector2f size, sf::Vector2f coordinates);
        void on_update(float dt);
};

#endif
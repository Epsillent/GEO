#include "entities/selector/selector.hpp"

Selector::Selector(sf::Color color, sf::Vector2f size, sf::Vector2f coordinates) {
    translate(coordinates);
    m_coorinates = coordinates;
    m_body = component_add<Sprite2D>();
    sf::RectangleShape &body = m_body->shape();
    body.setOutlineColor(color);
    body.setFillColor(sf::Color::Transparent);
    body.setOutlineThickness(10);
    body.setSize(size);
}

void Selector::on_update(float dt){
}

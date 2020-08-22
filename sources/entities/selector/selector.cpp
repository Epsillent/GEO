#include "entities/selector/selector.hpp"
Selector::Selector(sf::Color color, sf::Vector2f size, sf::Vector2f coordinates, Side side) {
    translate(coordinates);
    m_coorinates = coordinates;
    m_body = component_add<Sprite2D>();
    m_body->set_size(size);
    m_body->set_texture(&GeoPropeties::texture_pack->selector[side]);
}

void Selector::on_update(float dt){
}

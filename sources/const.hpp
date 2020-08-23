#ifndef CONST_H
#define CONST_H
#include "utils/texture_pack.hpp"

struct GeoPropeties {
    static const int generator_health;
    static const int shooter_health;
    static const int protector_health;
    static const int base_health;

    static const int figure_edge;
    static const int base_width;
    static const int base_height;

    static const int generator_price;
    static const int shooter_price;
    static const int protector_price;

    static const sf::Vector2f cell_size;
    static const sf::Vector2f selector_size;
    static const float selector_move_delay;

    static const sf::Vector2f offset_in_selector;
    static const sf::Vector2f grid_offset;
    static TexturePack *texture_pack;
};

#endif
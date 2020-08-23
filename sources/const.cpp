#include "const.hpp"

const int GeoPropeties::generator_health = 2;
const int GeoPropeties::protector_health = 5;
const int GeoPropeties::shooter_health   = 2;
const int GeoPropeties::base_health      = 5;

const int GeoPropeties::figure_edge = 100;
const int GeoPropeties::base_height = 300;
const int GeoPropeties::base_width  = 100;

const int GeoPropeties::generator_price = 3;
const int GeoPropeties::shooter_price   = 3;
const int GeoPropeties::protector_price = 3;

const sf::Vector2f GeoPropeties::cell_size(100,100);
const sf::Vector2f GeoPropeties::selector_size(120,120);
const float GeoPropeties::selector_move_delay = 0.2f;

const sf::Vector2f GeoPropeties::offset_in_selector(10,5);
const sf::Vector2f GeoPropeties::grid_offset(80,65);

TexturePack *GeoPropeties::texture_pack = nullptr;

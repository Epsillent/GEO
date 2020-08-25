#ifndef TEXTURE_PACK_H
#define TEXTURE_PACK_H

#include "engine.hpp"

struct TexturePack{
    sf::Texture battlefield;
    sf::Texture selector[2];
    sf::Texture protector[2];
    sf::Texture generator[2];
    sf::Texture shooter[2];
    sf::Texture base[2];
    sf::Texture remote_btn;
    sf::Texture local_btn;
    sf::Texture main_menu_button;
    sf::Texture main_menu_background;
    TexturePack(const std::string &path);
    ~TexturePack() = default;
    TexturePack(const TexturePack &other) = delete;
    TexturePack(TexturePack &&other) = delete;
};

#endif
#ifndef TEXTURE_PACK_H
#define TEXTURE_PACK_H

#include "engine.hpp"

struct TexturePack{
    sf::Texture battlefield;
    sf::Texture selector[2];
    sf::Texture protector[2];
    sf::Texture generator[2];
    sf::Texture shooter[2];
    TexturePack(const std::string &path);
    ~TexturePack() = default;
    TexturePack(const TexturePack &other) = delete;
    TexturePack(TexturePack &&other) = delete;
};

#endif
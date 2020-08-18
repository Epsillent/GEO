#ifndef PLAYER_H
#define PLAYER_H

#include "engine.hpp"

class Player: public GameObject {
    private:
        std::string m_status;
    public:
        Player();
};

#endif
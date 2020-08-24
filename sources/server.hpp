#ifndef GEO_SERVER
#define GEO_SERVER

#include "network/game_server.hpp"

class GeoServer: public GameServer{
public:
    GeoServer(uint16 port);
};


extern void launch_server(uint16 port);

#endif
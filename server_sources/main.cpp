#include "engine.hpp"
#include "network/game_server.hpp"



class GeoServer: public GameServer{

public:
    GeoServer():
        GameServer(25565)
    {}
};


int main(){
    GeoServer server;
    server.serve();
}
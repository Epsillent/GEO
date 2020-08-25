#include "server.hpp"
#include "utils/debug.hpp"
GeoServer::GeoServer(uint16 port):
    GameServer(port)
{

}
GeoServer *server = nullptr;

void launch_server(){
    Info("----LOCAL SERVER PROPERTIES----");
    Info("-------------------------------");
    Info("LocalIP:   " +sf::IpAddress::getLocalAddress().toString());
    Info("NetworkIP: " +sf::IpAddress::getPublicAddress().toString());
    Info("-------------------------------");
    server->serve();
}
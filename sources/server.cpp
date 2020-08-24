#include "server.hpp"
#include "utils/debug.hpp"
GeoServer::GeoServer(uint16 port):
    GameServer(port)
{

}

void launch_server(uint16 port){
    Info("----LOCAL SERVER PROPERTIES----");
    Info("-------------------------------");
    Info("LocalIP:   " +sf::IpAddress::getLocalAddress().toString());
    Info("NetworkIP: " +sf::IpAddress::getPublicAddress().toString());
    Info("Port:      " + std::to_string(port));
    Info("-------------------------------");
    GeoServer serv(port);
    serv.serve();
}
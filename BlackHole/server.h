#include <enet/enet.h>
#include <stdio.h>

class Server
{
public:
	ENetAddress address;
	ENetHost *server;
	ENetEvent event;
	int eventStatus;

	Server();
	void Client();
};
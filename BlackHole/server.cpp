#include "server.h"

Server::Server()
{
	// initialise enet server
	if (enet_initialize() != 0) {
		fprintf(stderr, "An error occured while initializing ENet.\n");
		return;
	}
	atexit(enet_deinitialize);

	address.host = ENET_HOST_ANY;
	/* Bind the server to port 12345. */
	address.port = 12345;

	server = enet_host_create(&address, 32, 2, 0, 0);

	if (server == NULL) {
		fprintf(stderr, "An error occured while trying to create an ENet server host\n");
		exit(EXIT_FAILURE);
	}

	// connect to enet host and then wait for events	
	eventStatus = 1;

	while (1) {
		eventStatus = enet_host_service(server, &event, 50000);

		// If we had some event that interested us
		if (eventStatus > 0) {
			switch (event.type) {
			case ENET_EVENT_TYPE_CONNECT:
				printf("(Server) We got a new connection from %x\n", event.peer->address.host);
				break;

			case ENET_EVENT_TYPE_RECEIVE:
				printf("(Server) Message from client : %s\n", event.packet->data);
				// Lets broadcast this message to all
				enet_host_broadcast(server, 0, event.packet);
				break;

			case ENET_EVENT_TYPE_DISCONNECT:
				printf("%s disconnected.\n", event.peer->data);
				// Reset client's information
				event.peer->data = NULL;
				break;

			}
		}
	}
}

void Server::Client() 
{

}
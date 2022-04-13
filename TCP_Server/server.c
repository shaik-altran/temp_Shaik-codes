#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

#define PORT 9002

int main()
{
	char server_msg[255] = "Hi welcome to the server";
	int server_socket;
	int status;
	int client_socket;
	struct sockaddr_in server_address;
	
	server_socket = socket(AF_INET,SOCK_STREAM,0);
	
	
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;

	status = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if(status < 0)
	{
		printf("Error in binding\n");
		exit(0);
	}

	if(listen(server_socket,1) == 0)
	{
		printf("Listening.....\n");
	}
		

	client_socket = accept(server_socket,NULL,NULL);

	send(client_socket, server_msg, sizeof(server_msg),0);
		

	close(server_socket);
}


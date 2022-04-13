#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9002

int main()
{
	int server_socket;
	struct sockaddr_in serverAddr;

	int client_socket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;

	char buffer[255];

	pid_t child_pid;

	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	if(server_socket < 0)
	{
		prntf("Error in connection\n");
		exit(0);
	}
	printf("Server Socket is created\n");

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port   = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	status = bind(server_socket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	if(status < 0)
	{
		printf("Error in binding\n");
		exit(0);
	}

	if(listen(server_socket,10) == 0)
		printf("Listening....\n");
	else
		printf("Error in binding\n");

	while(1)
	{
		client_socket = accept(server_socket, (struct sockaddr *) &newAddr, &addr_size);
		if(client_socket < 0)
		{
			printf("Problem in Connecting\n");
			exit(0);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
		if((childpid = fork()) == 0){
			close(so);

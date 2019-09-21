#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PORTNO 8085

int main(int argc, char *argv[])
{
	int  sockfd,clientfd;
	struct sockaddr_in server,client;
	int mysock;
	char buffer[2048];
	char servmsg[1024] = "Whats up !\n";
	int b;
	
	sockfd =  socket(AF_INET,SOCK_STREAM,0);
	if(sockfd < 0)	printf("Error creating socket");
	//printf("\nPORT NO set to 9090");	
	server.sin_port = htons(PORTNO);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	//printf("\nConfigured the IP Address");

	b = bind(sockfd,(struct sockaddr *)&server,sizeof(server));
	printf("\nTCP Server is Online\n");
	if(b < 0)	perror("Binding Failed");
	listen(sockfd,1);	
	clientfd = accept(sockfd,(struct sockaddr *)&client,&clientfd);
	printf("Received Client Connection\n\n");
	read(clientfd,buffer,2048);
	printf("Client : %s",buffer);
	write(clientfd,servmsg,1024);
	read(clientfd,buffer,2048);
	
	return 0;
	
}

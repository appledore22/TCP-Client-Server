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
	int clientfd,sockfd;
	struct sockaddr_in client;
	int myclient;
	char buffer[1024] = "Hello\n";
	char recvmsg[1024];
	int portno,b;
	
	clientfd =  socket(AF_INET,SOCK_STREAM,0);


	client.sin_family = AF_INET;
	client.sin_addr.s_addr = INADDR_ANY;
	client.sin_port = htons(PORTNO);

	int c = connect(clientfd,(struct sockaddr *)&client,sizeof(client));
	if(c<0) perror("Errror in Connection");
	recv(sockfd,&buffer,sizeof(buffer),0);
	write(clientfd,buffer,1024);
	read(clientfd,recvmsg,2048);
	printf("Server : %s",recvmsg);
	
	return 0;
}

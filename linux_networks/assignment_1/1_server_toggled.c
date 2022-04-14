#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

#define PORT 8000

int main()
{
	int sockfd, retval, accfd;

	struct sockaddr_in servaddr, clientaddr;
	socklen_t clilen;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sockfd < 0)
	{
		perror("socket: ");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	retval = bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval < 0)
	{
		perror("bind: ");
		exit(2);
	}

	listen(sockfd, 5);

	accfd = accept(sockfd, (struct sockaddr *) &clientaddr, &clilen);
	if(accfd < 0)
	{
		perror("accept: ");
		exit(3);
	}
	printf("Client connected\n");

	while(1)
	{
		char buff[100];
		int n;

		n = recv(accfd, buff, sizeof(buff), 0);
		if(n < 0)
		{
			perror("recv: ");
			exit(4);
		}
		printf("Rev'd data from client : %s\n", buff);

		for(int i=0; i<n; i++)
		{
			if(buff[i] >= 'a' && buff[i] <= 'z')
				buff[i] -= 32;
			else 
				buff[i] += 32;
		}

		send(accfd, buff, strlen(buff), 0);
		printf("Data sended to client\n");
	}	

	close(sockfd);
	return 0;
}

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
	int sockfd, retval;

	struct sockaddr_in servaddr;
	socklen_t addr_len;

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

	addr_len = sizeof(struct sockaddr_in);
//	addr_len = sizeof(servaddr);

//	inet_pton(AF_INET, serv_ip, &servaddr.sin_addr);
/*
	retval = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(retval < 0)
	{
		perror("connect: ");
		exit(2);
	}
*/	printf(".............Client connecting to server.............\n");

//	while(1)
//	{
		char buff[100];
		int n;
		
		//getchar();
		memset(buff, 0, sizeof(buff));
		printf("\nEnter message to send to server: \n");
		gets(buff);

		printf("String entered to send to client: %s\n",buff);
	
		n = sendto(sockfd, buff, strlen(buff), 0, (struct sockaddr *) &servaddr, addr_len);
		printf("Data sended to server n: %d\n",n);

		printf("\nWaiting for server data.........\n");
		n = recvfrom(sockfd, buff, sizeof(buff), 0 , (struct sockaddr *) &servaddr, &addr_len);
		if(n < 0)
		{
			perror("recv: ");
			exit(4);
		}
		printf("Rev'd data from server : %s\tof bytes: %d\n", buff, n);		
//	}	

	close(sockfd);
	return 0;
}

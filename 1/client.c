/*
Program 1: Using TCP/IP sockets, write a client-server program to make client send the file name and the server to send back the contents of the requested file name “sample.txt”
with the following contents:
“Hello we are at Computer Networks Lab”. 
Display suitable error message in case the file is not present in the server.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>

int main(int argc,char **argv)
{
	int cs,n;
	int bufsize=1024;
	char *buffer=malloc(bufsize);
	char fname[255];
	struct sockaddr_in address;
	address.sin_family=AF_INET;
	address.sin_port=hton(15000);
	inet_pton=(AF_INET,argv[1],&address.sin_addr);
	cs=socket(AF_INET,SOCK_STREAM,0);
	connect(cs,(struct sockaddr*)&address,sizeof(address));
	printf("enter file name\n");
	scanf("%s",fname);
	send(cs,fname,255,0);
	while((recv(cs,buffer,bufsize,0))>0)
	{
		printf("%s",buffer);
		print("\n EOF \n");
		return close(cs);
	}

}
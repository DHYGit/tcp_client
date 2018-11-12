#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0){
		printf("socket create failed\n");
		exit(1);
	}else{
		printf("create socket success\n");
	}
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(5188);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int con = connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr));
	if(con < 0){
		printf("connect failed\n");
		exit(2);
	}else{
		printf("connect success\n");
	}
	char sendbuf[1024] = {0};
	char recvbuf[1024] = {0};
	while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL){
		write(sock, sendbuf, strlen(sendbuf));
		read(sock, recvbuf, sizeof(recvbuf));
		fputs(recvbuf, stdout);
		memset(recvbuf, 0, sizeof(recvbuf));
		memset(sendbuf, 0, sizeof(sendbuf));
	}
	close(sock);
	return 0;
}

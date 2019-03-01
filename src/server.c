#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include "server.h"

#define PORT_NO 1042

/* should fork() this at some point to add multiple connections support */
void start_server(){ 
    int listen_desc = 0, conn_desc = 0, rec = 0;
    struct sockaddr_in serv_addr; 
    char sendBuff[1025], recvBuff[1025];
    time_t ticks; 

    listen_desc = socket(AF_INET, SOCK_STREAM, 0);

    memset(&serv_addr, '0', sizeof(serv_addr));
    memset(sendBuff, '0', sizeof(sendBuff)); 

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT_NO); 

    bind(listen_desc, (struct sockaddr*) &serv_addr, sizeof(serv_addr)); 
    printf("Listenint on port: %d\n", PORT_NO);

    listen(listen_desc, 10); 

    while(1){
        conn_desc = accept(listen_desc, (struct sockaddr*) NULL, NULL); 

	if(conn_desc != 0){
	  printf("A client connected.");
	}

        ticks = time(NULL);
        /* snprintf(sendBuff, sizeof(sendBuff), "%.24s\r\n", ctime(&ticks)); */
	printf(sendBuff, sizeof(sendBuff), "%s\r\n", ctime(&ticks));
        write(conn_desc, sendBuff, strlen(sendBuff)); 

	while((rec = read(conn_desc, recvBuff, sizeof(recvBuff-1))) > 0){
	  if(sizeof(recvBuff) > 0){
	    fputs(recvBuff, stdout);
	  }
	}

        /* close(conn_desc); */
	printf(recvBuff);
        sleep(1);
     }
}

int main(){
  start_server();
  return 0;
}

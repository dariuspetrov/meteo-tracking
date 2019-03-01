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
#define MAX_CONNECTIONS 2048

void admin_handler(){
  
}

void client_handler(){
  
}

void soap_handler(){
  
}

void server_handler(){ 
    int listen_desc = 0, conn_desc = 0;
    struct sockaddr_in server; 
    char sendBuff[1025], recvBuff[1025];
    time_t ticks; 

    listen_desc = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT_NO); 

    bind(listen_desc, (struct sockaddr*) &server, sizeof(server)); 
    listen(listen_desc, MAX_CONNECTIONS); 
    printf("Listenint on port: %d\n", PORT_NO);

    while(1){
      if(fork() >= 0){
	conn_desc = accept(listen_desc, (struct sockaddr*) NULL, NULL); 

	if(conn_desc > 0){
	  printf("A client connected - %d\n", conn_desc);
	  ticks = time(NULL);
	  printf(sendBuff, sizeof(sendBuff), "%s\r\n", ctime(&ticks));

	  /* write(conn_desc, sendBuff, strlen(sendBuff));  */
	  write(conn_desc, "Connected\n", 11);

	  while(read(conn_desc, recvBuff, sizeof(recvBuff - 1)) > 0){
	    printf("%s\n",recvBuff);
	    fflush(stdout);
	  }

	  sleep(1);
	  close(conn_desc);
	  printf("Client disconnected\n");
	  exit;
	}
      }
      else{
	// parent process continuing here.
      }
    }
}

int main(){
  server_handler();
  return 0;
}

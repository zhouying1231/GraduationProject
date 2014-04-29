#include "socketserver.hpp"
#include <iostream>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

using namespace std;

Server::Server()
{
    mServerPort = 9876;
    mListenServerAdd = INADDR_ANY;
}

Server::~Server()
{
    printf("Server defined\n");
}

void Server::StartListen()
{
    void* start(void* port);
    pthread_t* t_listen;
    pthread_create(t_listen,NULL,start,(void*)&mServerPort);
    pthread_join(*t_listen,NULL);

}

void* start(void* port)
{
  int *mPort = (int*) port;
  int listen_fd,accept_fd;
  struct sockaddr_in client_addr;
  int n;
  if((listen_fd=socket(AF_INET,SOCK_STREAM,0))<0)
  {
    // printf("Socket Error:%s\n\a",strerror(errno));
    exit(1);
  }
  bzero(&client_addr,sizeof(struct sockaddr_in));
  client_addr.sin_family=AF_INET;
  client_addr.sin_port=htons(*mPort);
  client_addr.sin_addr.s_addr=htonl(INADDR_ANY);
  n=1;
  setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(int));
  if(bind(listen_fd,(struct sockaddr *)&client_addr,sizeof(client_addr))<0)
  {
    // printf("Bind Error:%s\n\a",strerror(errno));
    exit(1);
  }
  listen(listen_fd,5);
  while(1)
  {
    accept_fd=accept(listen_fd,NULL,NULL);
    if((accept_fd<0)&&(errno==EINTR))
      continue;
    else if(accept_fd<0)
    {
      // printf("Accept Error:%s\n\a",strerror(errno));
      continue;
    }
    if((n=fork())==0)
    {
      char buffer[1024];
      close(listen_fd);
      n=read(accept_fd,buffer,1024);
      write(accept_fd,buffer,n);
      printf("read : %s",buffer);
      close(accept_fd);
      exit(0);
    }
    else if(n<0)
      printf("Fork Error:%d\n\a",errno);
   close(accept_fd);
  }
  return NULL;
}

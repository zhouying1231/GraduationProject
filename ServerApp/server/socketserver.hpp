
#ifndef _SERVER_H_
#define _SERVER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <netdb.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

using namespace std;

class Server 
{
public:
	Server();
	~Server();
     void StartListen();
private:
    int mServerPort;
    int mListenServerAdd;
};


#endif // _SERVER_H_

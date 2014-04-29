//--------------c plus plus-----------
#include <iostream>
//---------------boost------------------
#include <boost/asio.hpp>
//--------------Self Library-----------
#include "db.h"
#include "socketserver.hpp"

using namespace std;

int main()
{
    //--------Init and connect DataBase---------
    DB* mDB = new DB();
    mDB->InitDBConn();
    //--------Try to run asio Tcpserver---------
    Server* mServer = new Server();
    mServer->StartListen();

//    while(1)
//    {}
    return 0;
}


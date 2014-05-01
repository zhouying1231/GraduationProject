//--------------c plus plus-----------
#include <iostream>
//---------------boost------------------
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
//-------------postgresql-------------
#include <pqxx/pqxx>
//--------------Self Library-----------
#include "db.h"
#include "socketserver.hpp"

using namespace std;

int main()
{
    //--------Init and connect DataBase---------
    DB* mDB = new DB();
    mDB->InitDBConn();
    auto mConn = mDB->GetConn();
    //--------Try to run asio Tcpserver---------
    Server* mServer = new Server(mConn);
    mServer->StartListen();
    return 0;
}


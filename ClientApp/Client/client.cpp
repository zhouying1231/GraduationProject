#include "client.h"
#include <QDebug>
Client::Client(QObject *parent) :
    QObject(parent)
{
    mClient = new QTcpSocket();
}

void Client::SendMessage()
{
    char *data="hello qt!";
//    mClient->connectToHost(QHostAddress("218.244.137.34"), 9876);
    mClient->connectToHost(QHostAddress("127.0.0.1"), 9876);
    if(mClient->waitForConnected(3000))
    {
        qDebug()<<"Connected!";
        mClient->write(data);
        mClient->write(data);
        mClient->write(data);
        mClient->write(data);
        mClient->close();
    }
    else
    {
        qDebug()<<"Disconnected!";
    }
}

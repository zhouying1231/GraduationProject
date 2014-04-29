#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QtNetwork/QtNetwork>

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    void SendMessage();
signals:

public slots:

private:
    QTcpSocket* mClient;
};

#endif // CLIENT_H

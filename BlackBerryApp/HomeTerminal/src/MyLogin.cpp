/*
 * MyLogin.cpp
 *
 *  Created on: 2014-3-15
 *      Author: user
 */
#include "MyLogin.hpp"
#include <qDebug>
#include <QHostAddress>
#include <QCryptographicHash>


MyLogin::MyLogin()
{
	mServerAddress = "218.244.137.34";
	mServerPort = 4561;
	mClient = new QTcpSocket();
	connect(mClient,SIGNAL(readyRead()),this,SLOT(GetReturnMsg()));
	mActivityIndicator = NULL;
	mNotificationToast = NULL;
}

void MyLogin::Init(QObject* activityindicator,QObject* toast)
{
	mActivityIndicator = dynamic_cast<bb::cascades::ActivityIndicator*>(activityindicator);
	mNotificationToast = dynamic_cast<bb::system::SystemToast*>(toast);
}

void MyLogin::SendInfo(QString name,QString password)
{
	mActivityIndicator->start();
	QCryptographicHash* cryp = new QCryptographicHash(QCryptographicHash::Md5);
	cryp->addData(password.toLocal8Bit());
	QByteArray key = cryp->result().toHex();
	mClient->connectToHost(QHostAddress(mServerAddress),mServerPort);
	if(mClient->isOpen())
	{
		QString data = "{name : \"" + name + "\", password :\""+ key + "\"}";
		mClient->write(data.toLatin1().data());
	}
	else
	{
		mActivityIndicator->stop();
		mClient->close();
		mNotificationToast->setBody("Connect to Server Failed");
		mNotificationToast->startTimer(3);
		mNotificationToast->exec();
	}
}
void MyLogin::GetReturnMsg()
{
	mActivityIndicator->stop();
	bool ok;
	int result = mClient->readAll().toInt(&ok,10);
	Q_UNUSED(ok);
	qDebug()<<"result : "<<result;
	if(result == -1)
		mNotificationToast->setBody("Access denied");
	else if(result == -2)
		mNotificationToast->setBody("User doesn't exist");
	else
		mNotificationToast->setBody("Login success");
	mNotificationToast->startTimer(3);
	mNotificationToast->exec();
	mClient->close();
}

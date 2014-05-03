/*
 * MyLogin.hpp
 *
 *  Created on: 2014-3-15
 *      Author: user
 */

#ifndef MYLOGIN_HPP_
#define MYLOGIN_HPP_

#include <QObject>
#include <QtNetwork>
#include <QTcpSocket>
#include <bb/cascades/ActivityIndicator>
#include <bb/system/SystemToast>

class MyLogin : public QObject
{
	Q_OBJECT
public:
	MyLogin();
	virtual ~MyLogin(){}
	Q_INVOKABLE void Init(QObject* activityindicator,QObject* toast);
	Q_INVOKABLE void SendInfo(QString name,QString password);
public slots:
	void GetReturnMsg();
private:
	QString mServerAddress;
	int mServerPort;
	QTcpSocket* mClient;
	bb::cascades::ActivityIndicator* mActivityIndicator;
	bb::system::SystemToast* mNotificationToast;
};


#endif /* MYLOGIN_HPP_ */

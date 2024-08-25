#ifndef TCPSERVER_H
#define TCPSERVER_H

#include "tcpsocket.h"

#include <QTcpServer>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(int port);
    ~TcpServer();

public:
    bool run(); // 监听

signals:
    void signalTcpMsgComes(QByteArray&);

private slots:
    // 处理数据
    void dataProcessing(QByteArray &sendData, int descriptor);
    // 断开连接处理
    void socketDisconnected(int descriptor);
    void incomingConnect();

private:
    int m_port; // 端口号
    QList<TcpSocket*> m_connectList;
};

#endif // TCPSERVER_H

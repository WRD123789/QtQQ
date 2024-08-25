#include "tcpserver.h"
#include "tcpsocket.h"

#include <QMessageBox>
#include <QTcpSocket>

TcpServer::TcpServer(int port)
    : m_port(port)
{
    connect(this, &TcpServer::newConnection, this, &TcpServer::incomingConnect);
}

TcpServer::~TcpServer()
{

}

bool TcpServer::run()
{
    if (this->listen(QHostAddress::Any, m_port)) {
        qDebug() << QString("套接字监听端口 %1 成功!").arg(m_port);
        // ...

        return true;
    } else {
        qDebug() << "套接字监听失败!";

        return false;
    }
}

void TcpServer::incomingConnect()
{
    while (hasPendingConnections()) {
        // 获取新的套接字
        QTcpSocket *socket = nextPendingConnection();

        TcpSocket *tcpSocket = new TcpSocket(socket);
        tcpSocket->run();

        qDebug() << QString::fromLocal8Bit("新的连接: %1").arg(tcpSocket->socketDescriptor());

        connect(tcpSocket, &TcpSocket::signalGetDataFromClient,
                this, &TcpServer::dataProcessing);
        connect(tcpSocket, &TcpSocket::signalClientDisconnected,
                this, &TcpServer::socketDisconnected);

        m_connectList.append(tcpSocket);
    }
}

void TcpServer::dataProcessing(QByteArray &sendData, int descriptor)
{
    for (int i = 0; i < m_connectList.size(); i += 1) {
        TcpSocket *socket = m_connectList.at(i);
        if (socket->socketDescriptor() == descriptor) {
            // 用于调试
            qDebug() << "来自 IP: " << socket->getSocket()->peerAddress().toString() <<
                "收到的数据: " << QString(sendData);

            emit signalTcpMsgComes(sendData);
        }
    }
}

void TcpServer::socketDisconnected(int descriptor)
{
    for (int i = 0; i < m_connectList.size(); i += 1) {
        TcpSocket *socket = m_connectList.at(i);
        int desc = socket->socketDescriptor();
        if (desc == descriptor || desc == -1) {
            m_connectList.removeAt(i);
            socket->deleteLater();

            qDebug() << "TcpSocket 断开连接: " << desc;

            return;
        }
    }
}

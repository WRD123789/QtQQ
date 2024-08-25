#include "tcpsocket.h"

TcpSocket::TcpSocket(QTcpSocket *socket, QObject *parent)
    : m_socket(socket)
    , QTcpSocket{parent}
{}

TcpSocket::~TcpSocket()
{
    delete m_socket;
}

void TcpSocket::run()
{
    m_descriptor = this->m_socket->socketDescriptor();

    connect(this->m_socket, &QTcpSocket::readyRead, this, &TcpSocket::onReceiveData);
    connect(this->m_socket, &QTcpSocket::disconnected, this, &TcpSocket::onClientDisconnected);
}

void TcpSocket::onReceiveData()
{
    QByteArray buffer = this->m_socket->readAll();
    if (!buffer.isEmpty())
        emit signalGetDataFromClient(buffer, m_descriptor);
}

void TcpSocket::onClientDisconnected()
{
    emit signalClientDisconnected(m_descriptor);
}

#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QTcpSocket>

class TcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    TcpSocket(QTcpSocket *socket, QObject *parent = nullptr);
    ~TcpSocket();

public:
    void run(); // 初始化
    inline QTcpSocket *getSocket() { return m_socket; }

    qintptr socketDescriptor() const override { return m_descriptor; }

private slots:
    void onReceiveData();
    void onClientDisconnected();

signals:
    void signalGetDataFromClient(QByteArray&, int);
    void signalClientDisconnected(int);

private:
    qintptr m_descriptor; // 唯一标识
    QTcpSocket *m_socket;
};

#endif // TCPSOCKET_H

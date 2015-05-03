#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>


class Client
{
public:
    Client();

    Client(QString ip, qint16 port);

    ~Client();

    void connect_(void);

    void disconnect(void);

    int write(QString msg);

    void wait_();

private:
    QTcpSocket *client;
    QString _ip;
    qint16 _port;
};

#endif // CLIENT_H

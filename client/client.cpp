#include "client.h"
#include<windows.h>


Client::Client()
{
}

Client::Client(QString ip, qint16 port)
{
    client = new QTcpSocket();
   _ip = ip;
   _port = port;
}


Client::~Client(){
    client->disconnectFromHost();
    client->waitForDisconnected(3000);
}

void Client::connect_(){
    client->connectToHost(_ip, _port);
    client->waitForConnected(3000);
}

void Client::disconnect(){
    client->disconnectFromHost();
    client->waitForDisconnected(3000);
}

int Client::write(QString msg){
    return client->write(msg.toUtf8());
}

void Client::wait_(){
   client->flush();
    client->waitForReadyRead();
    while (client->read(2) == "OK") ;
}

#ifndef SOCKET_H
#define SOCKET_H

#pragma comment(lib, "ws2_32.lib")

#include <winsock.h>
#include <adscodes.h>

class Socket {

public:

	Socket(int buf_size);
	~Socket();
	int start();
	int connect();
	int read(wchar_t *strg);
	int code(wchar_t *strg);
	void send_ok();

private:
	SOCKET sock, client;
    SOCKADDR_IN sock_addr, client_addr;
	int recv_packet(SOCKET sd, char* p_out_buffer, int buffer_size);

	int sin_size;

	char *recvbuf;
    int recvbuflen;
    WSADATA data; // inizializzo la variabile che contiene le primitive di Winsock
	WORD pp;
	int err;

	LPWSTR UTF8toUnicode(LPCSTR InputString);
};




#endif
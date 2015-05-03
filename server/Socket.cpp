#include "socket.h"

Socket::Socket(int buf_size){
closesocket(sock);
WSACleanup();
recvbuf = new char[buf_size];
recvbuflen = buf_size;
err=0;
pp=MAKEWORD(2,0); // creo la variabile p che contiene la versione della wsock32.dll
}

Socket::~Socket(){
        closesocket(sock);
        WSACleanup();
}


int Socket::start(){
	err=WSAStartup(pp,&data); // inizializzo la wsock32.dll verificandone la mancanza di errori
if (err != 0) {
    return -1;
}

sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
if (sock == INVALID_SOCKET) {
    WSACleanup();
	return -1;
}

sin_size = sizeof(struct sockaddr_in);
///////////////////////////////////////////////////////////////////////////////////////////
sock_addr.sin_family=AF_INET; // indico il protocollo utilizzato (TCP/IP)
sock_addr.sin_port=htons(69); //indico la porta a cui connettere il socket
//sock_addr.sin_addr.s_addr = INADDR_ANY;
sock_addr.sin_addr.S_un.S_un_b.s_b1=127; // indico l'indirizzo IP
sock_addr.sin_addr.S_un.S_un_b.s_b2=0;
sock_addr.sin_addr.S_un.S_un_b.s_b3=0;
sock_addr.sin_addr.S_un.S_un_b.s_b4=1;
err=bind(sock,(struct sockaddr*)&sock_addr,sizeof(struct sockaddr_in));
if (err == SOCKET_ERROR) {
        closesocket(sock);
        WSACleanup();
		return -1;
}

err=listen(sock,1);
if (err == SOCKET_ERROR) {
        closesocket(sock);
        WSACleanup();
		return -1;
}

return 0;
}

int Socket::connect(){
	int fromlen=sizeof(client_addr);
	client=accept(sock, (struct sockaddr*)&client_addr, &fromlen);
	if (client == INVALID_SOCKET) {
    closesocket(sock);
    WSACleanup();
	return -1;
    }else return 0;
}

int Socket::read(wchar_t *strg){
	memset(recvbuf, 0, recvbuflen*(sizeof recvbuf[0]));
	err =recv(client, recvbuf, recvbuflen, 0);
		if (err > 0) {
		wcscpy(strg, UTF8toUnicode(recvbuf));
		return err;
        } else if (!err) return 0;
		else  return -1;
}

void Socket::send_ok(){
send(client, "OK", 2, 0);
}

LPWSTR Socket::UTF8toUnicode(LPCSTR InputString)
  {
      /* Check, if string is empty. */
      if ( (InputString == NULL) || (*InputString == '\0') )
      {
          return L"";
      }  
     /* Calculate length */
     int Length = MultiByteToWideChar(CP_UTF8, 0, InputString, -1, NULL, NULL); 
     /* Convert and return string */
     LPWSTR OutputString = new wchar_t[Length + 1];
     MultiByteToWideChar(CP_UTF8, 0, InputString, -1, OutputString, Length); 
     return OutputString;
}

int Socket::code(wchar_t *strg){
if ((strg[0] == 'S') && (strg[1] == 'T') && (strg[2] == 'R')) return 1;
else return -1;
}

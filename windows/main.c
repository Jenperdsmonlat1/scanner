#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>

#pragma comment(lib, "ws2_32.lib")

int main(int argc, char *argv[]) {
  
  char ip[16];
  int connection;
  
  if (argc > 1) {
    printf("IP to scan: %s", ip);
    strcpy(ip, argv[1]);
  }
  
  WSADATA WSAData;
  WSAStartup(MAKEWORD(2, 0), &WSAData);
  
  SOCKET sock;
  SOCKADDR_IN sin;
  
  sock = socket(AF_INET, SOCK_STREAM, 0);
  sin.sin_addr.s_addr = inet_addr(ip);
  sin.sin_family = AF_INET;
  
  for (int i = 0; i <= 65535; i++) {
    sin.sin_port = htons(i);
    connection = connect(sock, (SOCKADDR *)&sin, sizeof(sin));
    
    if (connection < 0) {
      printf("Le port %d est fermé.", i);
    } else {
      printf("Le port %d est ouvert.", i);
    }
  }
  
  WSACleanup();
  return 0;
}

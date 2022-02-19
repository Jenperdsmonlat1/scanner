#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include "functions.h"

void showBanner();

int main(int argc, char *argv[]) {

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    char ip[16];

    showBanner();

    printf("Saisissez l'ip a scanner: \n");
    scanf("%s", ip);

    if (sock < 0) {
        printf("La creation du socket n'a pas marche.\n");
        exit(0);
    }

    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        printf("L'adresse n'est pas valide.\n");
        exit(0);
    }

    for (int i = 1; i < 65536; i++) {
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            printf("Le port %d est ferme.\n", i);
        } else {
            printf("Le port %d est ouvert.\n", i);
            writeResult(i);
        }
    }
}

void showBanner() {
    setColor(1, 0);
    printf("███████╗ ██████╗ █████╗ ███╗   ██╗███╗   ██╗███████╗██████╗ \n");
    setColor(2, 0);
    printf("██╔════╝██╔════╝██╔══██╗████╗  ██║████╗  ██║██╔════╝██╔══██╗\n");
    setColor(3, 0);
    printf("███████╗██║     ███████║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝\n");
    setColor(4, 0);
    printf("╚════██║██║     ██╔══██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗\n");
    setColor(5, 0);
    printf("███████║╚██████╗██║  ██║██║ ╚████║██║ ╚████║███████╗██║  ██║\n");
    setColor(6, 0);
    printf("╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝\n");
    setColor(7, 0);

}
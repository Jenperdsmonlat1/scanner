#include <stdlib.h>
#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#endif

void setColor(int t, int f) {
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, f*16+t);
}

void writeResult(int port) {
    FILE* resultat = NULL;

    resultat = fopen("result.txt", "a");

    if (resultat != NULL) {
        fprintf(resultat, "Le port %d est ouvert.\n", port);
        fclose(resultat);
    } else {
        printf("Les resultats n'ont pas pu etre sauvegarde.\n");
    }
}
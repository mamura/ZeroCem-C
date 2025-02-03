#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clear()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void drawHeader()
{
    printf("\n\n");
    printf("*********************************\n");
    printf("*              ___              *\n");
    printf("*    JOGO     |[_]|     JOGO    *\n");
    printf("*   0 A 100   |+ ;|    0 A 100  *\n");
    printf("*             '---'             *\n");
    printf("*********************************\n");
}

void main() {
    int players;

    srand(time(0));
    int secretNumber = rand() % 100;

    clear();
    drawHeader();
}
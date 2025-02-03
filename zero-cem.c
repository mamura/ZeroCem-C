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
    printf("*******************************************\n");
    printf("*                   ___                   *\n");
    printf("*         JOGO     |[_]|     JOGO         *\n");
    printf("*        0 A 100   |+ ;|    0 A 100       *\n");
    printf("*                  '---'                  *\n");
    printf("*******************************************\n");
}

void drawWinner(int player)
{
    printf("*******************************************\n");
    printf("*            PARABENS JOGADOR %d           *\n", player);
    printf("*              VOCÊ VENCEU                *\n");
    printf("*            |@@@@|     |####|            *\n");
    printf("*            |@@@@|     |####|            *\n");
    printf("*            |@@@@|     |####|            *\n");
    printf("*            \\@@@@|     |####/            *\n");
    printf("*             \\@@@|     |###/             *\n");
    printf("*              `@@|_____|##'              *\n");
    printf("*                   (O)                   *\n");
    printf("*                .-'''''-.                *\n");
    printf("*              .'  * * *  `.              *\n");
    printf("*             :  *       *  :             *\n");
    printf("*            : ~  CAMPEÃO  ~ :            *\n");
    printf("*            : ~  0 A 100  ~ :            *\n");
    printf("*             :  *       *  :             *\n");
    printf("*              `.  * * *  .'              *\n");
    printf("*                `-.....-'                *\n");
    printf("*******************************************\n");
}

void drawLooser(int player)
{
    printf("**********************************************\n");
    printf("*           ／＞     フ                      *\n");
    printf("*　　　　　 | 　_　 _|                       *\n");
    printf("*　 　　　／` ミ＿xノ                        *\n");
    printf("*　　 　 /　　　 　 | VOCÊ PERDEU JOGADOR %d  *\n", player);
    printf("*　　　 /　 ヽ　　 ﾉ                         *\n");
    printf("*　 　 │　　|　|　|                          *\n");
    printf("*　／￣|　　 |　|　|                         *\n");
    printf("*　| (￣ヽ＿ヽ)__) __)                       *\n");
    printf("*　＼二つ                                    *\n");
    printf("**********************************************\n");
}

void main() {
    int players;
    int initRange = 0, endRange = 100;
    int kick = 0;

    srand(time(0));
    int secretNumber = rand() % 100;

    clear();
    drawHeader();
printf("%d", secretNumber);
    printf("# Adicione a quantidade de jogadores: ");
    scanf("%d", &players);
    printf("\n\n");

    while (secretNumber != kick)
    {
        for(int i = 1; i <= players; i++) {
            printf("## JOGADOR %d ##\n", i);
            printf("# Digite um numero de %d a %d: ", initRange, endRange);
            scanf("%d", &kick);
            printf("\n\n");
    
            if (kick == secretNumber) {
                drawWinner(i);

                continue;
            }

            // Chute Fora do Range
            if (kick < initRange || kick > endRange) {
                drawLooser(i);
                kick = secretNumber;

                continue;
            }

            if (kick < secretNumber) {
                initRange = kick;
            } else {
                endRange = kick;
            }
        }
    }
    
}
#include <stdio.h>

int checkWin(int board[3][3], int player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    // Check additional horizontal rows
    if ((board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
        (board[2][0] == player && board[2][1] == player && board[2][2] == player)) {
        return 1;
    }

    // Check additional vertical columns
    if ((board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
        (board[0][2] == player && board[1][2] == player && board[2][2] == player)) {
        return 1;
    }

    return 0;
}

int main() {
    int m[3][3] = { {0} };
    int i, a, b, c = 0;
    char s1[50], s2[50];
    printf("* WELCOME TO THE TIC-TACK-TOE GAME FOR 3X3 MATRIX *\n");
    printf("Player 1 enters the value as '9' which means X and player 2 as '6' which means O\n");
    printf("row number and column number starts from 0\n");
    printf("\nPlayer 1 enter your name: ");
    scanf("%s", s1);
    printf("Player 2 enter your name: ");
    scanf("%s", s2);

    for (i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            printf("%s Enter your row number and column number one by one: ", s1);
            scanf("%d %d", &a, &b);
            m[a][b] = 9;
            if(a>3 || b>3)
            {
                printf("enter correct row and column numbers!!!\n");
            }
            for (a = 0; a < 3; a++) {
                for (b = 0; b < 3; b++) {
                    printf("%d ", m[a][b]);
                }
                printf("\n");
            }
            a = 0;
            b = 0;
            if (checkWin(m, 9)) {
                printf("%s wins\n", s1);
                c++;
                break;
            }
        } else {
            printf("%s Enter row number and column number one by one: ", s2);
            scanf("%d %d", &a, &b);
            m[a][b] = 6;
            for (a = 0; a < 3; a++) {
                for (b = 0; b < 3; b++) {
                    printf("%d ", m[a][b]);
                }
                printf("\n");
            }
            a = 0;
            b = 0;
            if (checkWin(m, 6)) {
                printf("%s Wins\n", s2);
                c++;
                break;
            }
        }
    }
    if (c == 0)
        printf("SORRY, NO PLAYER WINS ---- TRY AGAIN\n");

    return 0;
}

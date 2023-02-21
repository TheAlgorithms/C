/**
 * @file
 * @author [Carlos Rafael](https://github.com/CarlosZoft)
 * @author [Herick Lima](https://github.com/hericklima22)
 * @brief [naval_battle](https://en.wikipedia.org/wiki/Battleship_(game))
 * implementation in C using only the stdio.h for Standard Input and Output.
 * @details  Naval battle is a game, to be played by two people. It consists of
 * knocking down the enemy ship, through shots , when hit the ship is
 * revealed with the respective number of its size. Example: size 3 = 3 3 3 on
 * the board.
 * To play - boats over size 1, need direction; V -> vertical and H ->
 * horizontal. Example Input 1 A H -> line 1, column A, direction H
 * (Horizontal).
 */

#include <stdio.h>  /// for Standard Input Output

/**
 * @brief Function validEntryLineColumn
 * Responsible for validating entries, for positioning boats
 * @param line matrix row
 * @param column matrix column
 * @returns if the row and column are valid
 */
int validEntryLineColumn(int line, char column)
{
    if ((line >= 1 && line <= 10) && (column >= 65 && column <= 74))
    {
        return 1;
    }

    return 0;
}
/**
 * @brief Function validatePosition
 * Responsible for checking if the position can receive the boat.
 * @param mat board
 * @param boat boat
 * @param line matrix row
 * @param column matrix column
 * @returns if the position is valid
 */
int validatePosition(int mat[10][10], int boat, int line, int column,
                     char guide)
{
    int cont = 0;
    int i, j;

    if (line < 0 || line > 9 || column < 0 || column > 9 ||
        (guide != 'H' && guide != 'V') || boat < 1 || boat > 3)
    {
        return 0;
    }

    if (guide == 'H')
    {
        if ((10 - column) < boat)
        {
            return 0;
        }
        else
        {
            for (j = column; j < (column + boat); j++)
            {
                if (mat[line][j] == 0)
                {
                    cont++;
                }
            }
        }
    }

    if (guide == 'V')
    {
        if ((10 - line) < boat)
        {
            return 0;
        }

        else
        {
            for (i = line; i < (line + boat); i++)
            {
                if (mat[i][column] == 0)
                {
                    cont++;
                }
            }
        }
    }

    if (cont == boat)
    {
        return 1;
    }
    return 0;
}
/**
 * @brief Function canShoot
 * Responsible to verify that it is a valid position to shoot
 * @param mat board
 * @param line matrix row
 * @param column matrix column
 * @returns if the position is valid for shooting
 */

int canShoot(int mat[10][10], int line, int column)
{
    if (mat[line][column] == -2 || mat[line][column] == 10 ||
        mat[line][column] == 20 || mat[line][column] == 30 ||
        mat[line][column] == 50)
    {
        return 0;
    }

    return 1;
}
/**
 * @brief Function positionBoat
 * Responsible for placing the boats on the board, according to the size.
 * @param mat board
 * @param boat boat
 */
void positionBoat(int mat[10][10], int boat)
{
    int line, j;
    char column, guide;

    if (boat == 1)
    {
        scanf("%d %c", &line, &column);

        while (validEntryLineColumn(line, column) != 1 ||
               validatePosition(mat, boat, (line - 1), (column - 65), 'H') != 1)
        {
            printf("Position unavailable!\n");
            scanf("%d %c", &line, &column);
        }
    }

    else
    {
        scanf("%d %c %c", &line, &column, &guide);

        while (validEntryLineColumn(line, column) == 0 ||
               validatePosition(mat, boat, (line - 1), (column - 65), guide) ==
                   0)
        {
            printf("Position unavailable!\n");
            scanf("%d %c %c", &line, &column, &guide);
        }
    }

    int aux = column - 'A';
    line -= 1;

    if (boat == 1)
    {
        for (j = aux; j < (aux + boat); j++)
        {
            mat[line][j] = boat;
        }

        for (int a = line - 1; a < (line + boat + 1); a++)
        {
            for (int b = aux - 1; b < (aux + boat + 1); b++)
            {
                if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                {
                    if (mat[a][b] != boat)
                    {
                        mat[a][b] = -1;
                    }
                }
            }
        }
    }

    if (guide == 'H')
    {
        for (j = aux; j < (aux + boat); j++)
        {
            mat[line][j] = boat;
        }
        if (boat == 3)
        {
            for (int a = line - 1; a < (line + boat - 1); a++)
            {
                for (int b = aux - 1; b < (aux + boat + 1); b++)
                {
                    if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                    {
                        if (mat[a][b] != boat)
                        {
                            mat[a][b] = -1;
                        }
                    }
                }
            }
        }

        else
        {
            for (int a = line - 1; a < (line + boat); a++)
            {
                for (int b = aux - 1; b < (aux + boat + 1); b++)
                {
                    if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                    {
                        if (mat[a][b] != boat)
                        {
                            mat[a][b] = -1;
                        }
                    }
                }
            }
        }
    }

    if (guide == 'V')
    {
        for (j = line; j < (line + boat); j++)
        {
            mat[j][aux] = boat;
        }
        if (boat == 3)
        {
            for (int a = line - 1; a < (line + boat + 1); a++)
            {
                for (int b = aux - 1; b < (aux + boat - 1); b++)
                {
                    if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                    {
                        if (mat[a][b] != boat)
                        {
                            mat[a][b] = -1;
                        }
                    }
                }
            }
        }

        else
        {
            for (int a = line - 1; a < (line + boat + 1); a++)
            {
                for (int b = aux - 1; b < (aux + boat); b++)
                {
                    if (a >= 0 && a <= 9 && b >= 0 && b <= 9)
                    {
                        if (mat[a][b] != boat)
                        {
                            mat[a][b] = -1;
                        }
                    }
                }
            }
        }
    }
}
/**
 * @brief Function printMessage
 * Responsible for printing the auxiliary message
 * @param msg msg with board
 */
void printMessage(char *msg)
{
    printf("************************\n");
    printf("*\n");
    printf("* %s\n", msg);
    printf("*\n");
    printf("************************\n");
}
/**
 * @brief Function printMessageScore
 * Responsible for printing the score messages
 * @param pts1 player 1 score
 * @param pts2 player 2 score
 */
void printMessageScore(int pts1, int pts2)
{
    printf("************************\n");
    printf("*\n");
    printf("* Player'S SCORE 1: %02d\n", pts1);
    printf("* Player'S SCORE 2: %02d\n", pts2);
    printf("*\n");
    printf("************************\n");
}
/**
 * @brief Function printTable
 * Responsible for printing the board
 * @param logic return of the logical matrix
 * @param stage game step
 * @returns char for visual matrix
 */
char printTable(int logic, int stage)
{
    if (stage == 0)
    {
        if (logic == 0)
        {
            return '.';
        }

        else if (logic == -1)
        {
            return '*';
        }

        else if (logic == 1)
        {
            return '1';
        }

        else if (logic == 2)
        {
            return '2';
        }

        else
        {
            return '3';
        }
    }

    else
    {
        if (logic == 0 || logic == -1 || logic == 1 || logic == 2 || logic == 3)
        {
            return '.';
        }

        else if (logic == -2)
        {
            return 'x';
        }

        else if (logic == 10 || logic == 20 || logic == 30)
        {
            return 'N';
        }

        else
        {
            return 'A';
        }
    }
}
/**
 * @brief Function printsTray
 * Responsible for printing the visual board for the user
 * @param mat Matrix
 * @param stage game step
 */
void printsTray(int mat[10][10], int stage)
{
    int logic;
    char imp;

    printf("     ");
    for (int i = 65; i < 75; i++)
    {
        printf("%c", i);
        if (i < 74)
        {
            printf(" ");
        }
    }
    printf("\n");

    for (int i = 0; i < 12; i++)
    {
        if (i > 0 && i < 11)
        {
            printf("%02d ", i);
        }

        else
        {
            printf("   ");
        }

        for (int j = 0; j < 12; j++)
        {
            if ((i > 0 && i < 11) && (j > 0 && j < 11))
            {
                logic = mat[i - 1][j - 1];
                imp = printTable(logic, stage);
                printf("%c", imp);
            }
            else
            {
                printf("#");
            }

            if (j < 11)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
/**
 * @brief Function shoot
 * Responsible for saying if he hit a boat
 * @param mat board
 * @param line matrix row
 * @param column matrix column
 */
void shoot(int mat[10][10], int line, int column)
{
    if (mat[line][column] == 0 || mat[line][column] == -1)
    {
        mat[line][column] = -2;
    }

    else if (mat[line][column] == 1)
    {
        mat[line][column] = 10;
    }

    else if (mat[line][column] == 2)
    {
        mat[line][column] = 20;
    }

    else if (mat[line][column] == 3)
    {
        mat[line][column] = 30;
    }
}
/**
 * @brief Function calculateScore
 * Responsible for calculating the score obtained during the game
 * @param mat board
 * @param line matrix row
 * @param column matrix column
 * @returns resulting score
 */

int calculateScore(int mat[10][10], int line, int column)
{
    int c = 0, b = 0, e = 0, d = 0;

    if (mat[line][column] == 10)
    {
        mat[line][column] = 50;
        return 2;
    }

    else if (mat[line][column] == 20)
    {
        if (mat[line + 1][column] == 20)
        {
            b = 1;
        }

        if (mat[line - 1][column] == 20)
        {
            c = 1;
        }

        if (mat[line][column + 1] == 20)
        {
            d = 1;
        }

        if (mat[line][column - 1] == 20)
        {
            e = 1;
        }

        if (b == 1)
        {
            if (mat[line + 1][column] == 20)
            {
                mat[line][column] = 50;
                mat[line + 1][column] = 50;
                return 4;
            }
            else
            {
                return 0;
            }
        }

        if (c == 1)
        {
            if (mat[line - 1][column] == 20)
            {
                mat[line][column] = 50;
                mat[line - 1][column] = 50;
                return 4;
            }
            else
            {
                return 0;
            }
        }

        if (d == 1)
        {
            if (mat[line][column + 1] == 20)
            {
                mat[line][column] = 50;
                mat[line][column + 1] = 50;
                return 4;
            }
            else
            {
                return 0;
            }
        }

        if (e == 1)
        {
            if (mat[line][column - 1] == 20)
            {
                mat[line][column] = 50;
                mat[line][column - 1] = 50;
                return 4;
            }
            else
            {
                return 0;
            }
        }
    }

    else if (mat[line][column] == 30)
    {
        if (mat[line + 1][column] == 30)
        {
            b = 1;
        }

        if (mat[line - 1][column] == 30)
        {
            c = 1;
        }
        if (mat[line][column + 1] == 30)
        {
            d = 1;
        }

        if (mat[line][column - 1] == 30)
        {
            e = 1;
        }

        if (b == 1 && c == 1)
        {
            if (mat[line + 1][column] == 30 && mat[line - 1][column] == 30)
            {
                mat[line][column] = 50;
                mat[line + 1][column] = 50;
                mat[line - 1][column] = 50;
                return 7;
            }
            else
            {
                return 0;
            }
        }

        else if (d == 1 && e == 1)
        {
            if (mat[line][column + 1] == 30 && mat[line][column - 1] == 30)
            {
                mat[line][column] = 50;
                mat[line][column - 1] = 50;
                mat[line][column + 1] = 50;
                return 7;
            }
            else
            {
                return 0;
            }
        }

        else if (d == 1)
        {
            if (mat[line][column + 1] == 30 && mat[line][column + 2] == 30)
            {
                mat[line][column] = 50;
                mat[line][column + 1] = 50;
                mat[line][column + 2] = 50;
                return 7;
            }
            else
            {
                return 0;
            }
        }

        else if (e == 1)
        {
            if (mat[line][column - 1] == 30 && mat[line][column - 2] == 30)
            {
                mat[line][column] = 50;
                mat[line][column - 1] = 50;
                mat[line][column - 2] = 50;
                return 7;
            }
            else
            {
                return 0;
            }
        }

        else if (c == 1)
        {
            if (mat[line - 1][column] == 30 && mat[line - 2][column] == 30)
            {
                mat[line][column] = 50;
                mat[line - 1][column] = 50;
                mat[line - 2][column] = 50;
                return 7;
            }
            else
            {
                return 0;
            }
        }

        else if (b == 1)
        {
            if (mat[line + 1][column] == 30 && mat[line + 2][column] == 30)
            {
                mat[line][column] = 50;
                mat[line + 1][column] = 50;
                mat[line + 2][column] = 50;
                return 7;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
/**
 * @brief Function printPositioning
 * Responsible for printing messages for positioning boats on the board; of
 * player 1 and 2
 * @param Player number representing the Player
 * @param boat number that represents the boat
 * @param nm which message to print
 */
void printPositioning(int Player, int boat, int nm)
{
    if (Player == 1)
    {
        char msg1[60] = "Player 1 - Position the size boat 1 (1/6)";
        char msg2[60] = "Player 1 - Position the size boat 1 (2/6)";
        char msg3[60] = "Player 1 - Position the size boat 1 (3/6)";
        char msg4[60] = "Player 1 - Position the size boat 1 (4/6)";
        char msg5[60] = "Player 1 - Position the size boat 1 (5/6)";
        char msg6[60] = "Player 1 - Position the size boat 1 (6/6)";

        char msg7[60] = "Player 1 - Position the size boat 2 (1/4)";
        char msg8[60] = "Player 1 - Position the size boat 2 (2/4)";
        char msg9[60] = "Player 1 - Position the size boat 2 (3/4)";
        char msg10[60] = "Player 1 - Position the size boat 2 (4/4)";

        char msg11[60] = "Player 1 - Position the size boat 3 (1/2)";
        char msg12[60] = "Player 1 - Position the size boat 3 (2/2)";

        if (boat == 1)
        {
            if (nm == 1)
            {
                printMessage(msg1);
            }
            else if (nm == 2)
            {
                printMessage(msg2);
            }
            else if (nm == 3)
            {
                printMessage(msg3);
            }

            else if (nm == 4)
            {
                printMessage(msg4);
            }

            else if (nm == 5)
            {
                printMessage(msg5);
            }

            else if (nm == 6)
            {
                printMessage(msg6);
            }
        }
        else if (boat == 2)
        {
            if (nm == 1)
            {
                printMessage(msg7);
            }
            else if (nm == 2)
            {
                printMessage(msg8);
            }
            else if (nm == 3)
            {
                printMessage(msg9);
            }
            else if (nm == 4)
            {
                printMessage(msg10);
            }
        }
        else if (boat == 3)
        {
            if (nm == 1)
            {
                printMessage(msg11);
            }
            if (nm == 2)
            {
                printMessage(msg12);
            }
        }
    }

    if (Player == 2)
    {
        char msg1[60] = "Player 2 - Position the size boat 1 (1/6)";
        char msg2[60] = "Player 2 - Position the size boat 1 (2/6)";
        char msg3[60] = "Player 2 - Position the size boat 1 (3/6)";
        char msg4[60] = "Player 2 - Position the size boat 1 (4/6)";
        char msg5[60] = "Player 2 - Position the size boat 1 (5/6)";
        char msg6[60] = "Player 2 - Position the size boat 1 (6/6)";

        char msg7[60] = "Player 2 - Position the size boat 2 (1/4)";
        char msg8[60] = "Player 2 - Position the size boat 2 (2/4)";
        char msg9[60] = "Player 2 - Position the size boat 2 (3/4)";
        char msg10[60] = "Player 2 - Position the size boat 2 (4/4)";

        char msg11[60] = "Player 2 - Position the size boat 3 (1/2)";
        char msg12[60] = "Player 2 - Position the size boat 3 (2/2)";

        if (boat == 1)
        {
            if (nm == 1)
            {
                printMessage(msg1);
            }
            else if (nm == 2)
            {
                printMessage(msg2);
            }
            else if (nm == 3)
            {
                printMessage(msg3);
            }
            else if (nm == 4)
            {
                printMessage(msg4);
            }
            else if (nm == 5)
            {
                printMessage(msg5);
            }
            else if (nm == 6)
            {
                printMessage(msg6);
            }
        }
        else if (boat == 2)
        {
            if (nm == 1)
            {
                printMessage(msg7);
            }
            else if (nm == 2)
            {
                printMessage(msg8);
            }
            else if (nm == 3)
            {
                printMessage(msg9);
            }
            else if (nm == 4)
            {
                printMessage(msg10);
            }
        }
        else if (boat == 3)
        {
            if (nm == 1)
            {
                printMessage(msg11);
            }
            else if (nm == 2)
            {
                printMessage(msg12);
            }
        }
    }
}
/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    int Player1[10][10];
    int Player2[10][10];
    int plays = 1;
    int pts1 = 0, pts2 = 0, a1 = 0, a2 = 0;
    int line, col = 0, lin = 0;
    char column;

    // filling matrix with 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Player1[i][j] = 0;
            Player2[i][j] = 0;
        }
    }

    // positioning boats
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i == 1)
            {
                printPositioning(i, 1, j);
                printsTray(Player1, 0);
                positionBoat(Player1, 1);
            }
            else if (i == 2)
            {
                printPositioning(i, 1, j);
                printsTray(Player2, 0);
                positionBoat(Player2, 1);
            }
        }
        for (int j = 1; j <= 4; j++)
        {
            if (i == 1)
            {
                printPositioning(i, 2, j);
                printsTray(Player1, 0);
                positionBoat(Player1, 2);
            }
            else if (i == 2)
            {
                printPositioning(i, 2, j);
                printsTray(Player2, 0);
                positionBoat(Player2, 2);
            }
        }
        for (int j = 1; j <= 2; j++)
        {
            if (i == 1)
            {
                printPositioning(i, 3, j);
                printsTray(Player1, 0);
                positionBoat(Player1, 3);
            }
            else if (i == 2)
            {
                printPositioning(i, 3, j);
                printsTray(Player2, 0);
                positionBoat(Player2, 3);
            }
        }
    }

    // starting the game
    while (plays <= 40)
    {
        if (plays % 2 != 0)
        {
            printMessageScore(pts1, pts2);
            printMessage("Player 1's turn");
            printsTray(Player2, 1);
            scanf("%d %c", &line, &column);

            while (validEntryLineColumn(line, column) != 1 ||
                   canShoot(Player2, line - 1, column - 65) != 1)
            {
                line = 0;
                column = 'a';
                printf("Position unavailable!\n");
                scanf("%d %c", &line, &column);
            }
            lin = line - 1;
            col = column - 65;
            shoot(Player2, lin, col);
            a1 = pts1;
            pts1 += calculateScore(Player2, lin, col);

            if (a1 != pts1)
            {
                printMessage("Player 1 DROPPED A BOAT!");
            }
        }
        else
        {
            printMessageScore(pts1, pts2);
            printMessage("Player 2's turn");
            printsTray(Player1, 1);
            scanf("%d %c", &line, &column);

            while (validEntryLineColumn(line, column) != 1 ||
                   canShoot(Player1, line - 1, column - 65) != 1)
            {
                printf("Position unavailable!\n");
                scanf("%d %c", &line, &column);
            }
            lin = line - 1;
            col = column - 65;
            shoot(Player1, lin, col);
            a2 = pts2;
            pts2 += calculateScore(Player1, lin, col);

            if (a2 != pts2)
            {
                printMessage("Player 2 DROPPED A BOAT!");
            }
        }

        plays++;
    }
    /**
     * the one with the most points wins, or the one who knocks down all boats
     * first.
     */
    printMessage("END GAME\n");
    printMessageScore(pts1, pts2);

    return 0;
}

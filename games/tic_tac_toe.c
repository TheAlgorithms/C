/**
 * @file tic-tac-toe.c
 * @author [vivekboss99](github.com/vivekboss99)
 * @author [Krishna Vedala](https://github.com/kvedala)
 * @brief [Tic-Tac-Toe game](https://en.wikipedia.org/wiki/Tic-tac-toe)
 * implementation in C
 * @details  Tic-Tac-Toe Game,where the user can decide to play with the
 * computer(single player mode) or with other user(double player mode) , the
 * code as an array named 'game_table' which is the table and user needs to
 * enter the position inside the array(from 1-9) where he/she wants to place 'X'
 * or 'O' on the table.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Functions Declarations
static void singlemode();
static void doublemode();
static void placex(int);  // used for placing position of X by the 1st player
static void place();      // used by the computer to place O
static void placey(int);  // used in Double Player mode by the 2nd player to
                          // place the position of O
int checkwin();  // checks everytime when a player or computer places 'X' or 'O'

/** Tic-Tac-Toe table, so basically we are using variable 'game_table' as the
 * table(size:3X3) and updating it regularly
 */
static char game_table[9];

/**
 * Main program function.
 * @returns 0 on clean exit.
 * @note No checks are included for program execution failures!
 */
int main()
{
    srand((unsigned int)time(NULL));
    int l = 0;
    do
    {
        int n = 0;

        // filling the table with multiple asterisks
        for (int i = 0; i < 9; i++) game_table[i] = '*';

        // displaying the main menu
        printf("***************************************\n");
        printf("*************TIC TAC TOE***************\n");
        printf("***************************************\n");
        printf("***********1. YOU vs COMPUTER ***********\n");
        printf("***********2. YOU vs PLAYER ***********\n");
        printf("***********3.EXIT *********************\n");
        printf("Enter your choice : ");
        scanf("%d", &n);

        switch (n)  // switch case to select between single player mode or
                    // double player mode
        {
        case 1:
            singlemode();
            break;
        case 2:
            doublemode();
            break;
        default:
            printf("THANK YOU and EXIT!");
        }

        printf("Next game ? : ");
        printf("Enter 1 – YES and 0 - NO ");
        scanf("%d", &l);

    } while (l == 1);

    return 0;
}

/**
 * @brief Implementation of game vs computer
 *
 * @returns None
 */
void singlemode()
{
    int m;
    int k = 0;
    int table_fill_count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", game_table[k]);
            k++;
        }

        printf("\n");
    }

    for (int x = 1; x < 10; x++)
    {
        k = 0;

        printf("Where would you like to place 'x' ");
        scanf("%d", &m);

        placex(m);
        if (table_fill_count < 4)
        {
            place();
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%c ", game_table[k]);
                k++;
            }

            printf("\n");
        }
        table_fill_count++;
        int o = checkwin();

        if (o == -1 || o == -2)
        {
            if (o == -1)
            {
                printf("YOU WIN\n");
            }
            if (o == -2)
            {
                printf("YOU LOSE\n");
            }

            break;
        }

        if (table_fill_count == 4)
        {
            printf("\nDRAW ");
            break;
        }
    }
}

/**
 * @brief Implementation of game vs another player.
 *
 * @returns None
 */
void doublemode()
{
    int m;
    int e1;
    int k = 0;
    int doublemode_table_count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", game_table[k]);
            k++;
        }

        printf("\n");
    }
    for (int x = 1; x < 10; x++)
    {
        k = 0;

        printf("PLAYER1 - where would you like to place 'x' : ");
        scanf("%d", &m);

        placex(m);
        if (doublemode_table_count < 4)
        {
            printf("PLAYER2 - where would you like to place 'o' : ");
            scanf("%d", &e1);

            placey(e1);
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%c ", game_table[k]);
                k++;
            }

            printf("\n");
        }
        doublemode_table_count++;
        int o = checkwin();

        if (o == -1 || o == -2)
        {
            if (o == -1)
            {
                printf("Player 1 WIN\n");
            }
            if (o == -2)
            {
                printf("Player 2 WIN\n");
            }

            break;
        }
        if (doublemode_table_count == 4)
        {
            printf("\nDRAW ");
            break;
        }
    }
}

int check_placex()
{
    char input[50];
    int n1;
    while (1)
    {
        fgets(input, 49, stdin);
        if (strlen(input) > 2 || strlen(input) == 0)
        {
            fprintf(stderr, "Invalid move, Enter number 1 - 9: ");
            continue;
        }
        if (sscanf(input, "%d", &n1) != 1)
        {
            fprintf(stderr, "Invalid move, Enter number 1 - 9: ");
            continue;
        }
        if ((game_table[n1 - 1] == 'x') || (game_table[n1 - 1]) == 'o' ||
            (n1 == 0))
        {
            fprintf(stderr, "Already allocated, Enter number: ");
            continue;
        }
        return n1;
    }
}

/**
 * @brief Update table by placing an `X`
 *
 * @param m location to place `X`
 *
 * @returns None
 */
void placex(int m)
{
    int n1 = 0;
    if (m >= 1 && m <= 9)
    {
        if (game_table[m - 1] != 'x' && game_table[m - 1] != 'o')
        {
            game_table[m - 1] = 'x';
        }
        else
        {
            int n = check_placex();
            placex(n);
        }
    }
    else
    {
        int n = check_placex();
        placex(n);
    }
}
/**
 * @brief Update table by placing an `O`
 *
 * @returns None
 */
void place()
{
    int e = rand() % 9;

    if (e >= 0 && e <= 8)
    {
        if (game_table[e] != 'x' && game_table[e] != 'o')
        {
            game_table[e] = 'o';
            printf("\n Computer placed at %d position\n", e + 1);
        }
        else
        {
            place();
        }
    }
}
/**
 * @brief Update table by placing an `O`
 *
 * @param e1 location to place `O`
 *
 * @returns None
 */
void placey(int e1)
{
    int n1 = 0;
    if (e1 >= 1 && e1 <= 9)
    {
        if (game_table[e1 - 1] != 'x' && game_table[e1 - 1] != 'o')
        {
            game_table[e1 - 1] = 'o';
        }
        else
        {
            int n = check_placex();
            placex(n);
        }
    }
    else
    {
        int n = check_placex();
        placex(n);
    }
}
/**
 * @brief Implementation of win conditon checker for 'X' or 'O' whenever the
 * table is updated
 *
 * @returns -1: if 'X' won
 * @returns -2: if 'O' won
 * @returns 0: if there is no win condition for 'X' or 'O'
 */
#define TEST_RETURN_WINNER(result_holder, function) \
    result_holder = function();                     \
    if (result_holder != 0)                         \
    {                                               \
        return result_holder;                       \
    }

int checkwin()
{
    int check_rows();
    int check_columns();
    int check_diagonals();

    int winner;
    TEST_RETURN_WINNER(winner, check_rows);
    TEST_RETURN_WINNER(winner, check_columns);
    return check_diagonals();
}

int check_rows()
{
    for (size_t i = 0; i < 3; i++)
    {
        int count_x = 0;
        int count_o = 0;
        for (size_t j = 0; j < 3; j++)
        {
            /* [(i * 3) + (j)] == [i][j] */
            if (game_table[(i * 3) + (j)] == 'x')
            {
                ++count_x;
            }
            else if (game_table[(i * 3) + (j)] == 'o')
            {
                ++count_o;
            }
        }
        if (count_x == 3)
        {
            return -1;
        }
        if (count_o == 3)
        {
            return -2;
        }
    }
    return 0;
}

int check_columns()
{
    for (size_t i = 0; i < 3; i++)
    {
        int count_x = 0;
        int count_o = 0;
        for (size_t j = 0; j < 3; j++)
        {
            /* [(j * 3) + (i)] == [j][i] */
            if (game_table[(j * 3) + (i)] == 'x')
            {
                ++count_x;
            }
            else if (game_table[(j * 3) + (i)] == 'o')
            {
                ++count_o;
            }
        }
        if (count_x == 3)
        {
            return -1;
        }
        if (count_o == 3)
        {
            return -2;
        }
    }
    return 0;
}

int check_diagonals()
{
    int check_right_diagonal();
    int check_left_diagonal();

    int winner;
    TEST_RETURN_WINNER(winner, check_right_diagonal);
    return check_left_diagonal();
}

int check_right_diagonal()
{
    int count_x = 0;
    int count_o = 0;
    for (size_t i = 0; i < 3; i++)
    {
        /* [(i * 3) + (i)] == [i][i] */
        if (game_table[(i * 3) + (i)] == 'x')
        {
            ++count_x;
        }
        else if (game_table[(i * 3) + (i)] == 'o')
        {
            ++count_o;
        }
    }
    if (count_x == 3)
    {
        return -1;
    }
    if (count_o == 3)
    {
        return -2;
    }
    return 0;
}

int check_left_diagonal()
{
    int count_x = 0;
    int count_o = 0;
    for (size_t i = 0; i < 3; i++)
    {
        /* [(i * 3) + (3 - 1 - i)] == [i][3 - i - 1] */
        if (game_table[(i * 3) + (3 - 1 - i)] == 'x')
        {
            ++count_x;
        }
        else if (game_table[(i * 3) + (3 - 1 - i)] == 'o')
        {
            ++count_o;
        }
    }
    if (count_x == 3)
    {
        return -1;
    }
    if (count_o == 3)
    {
        return -2;
    }
    return 0;
}
#undef TEST_RETURN_WINNER

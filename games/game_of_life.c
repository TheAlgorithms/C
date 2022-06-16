/**
 * @file game-of-life.c
 * @author [DanArmor](github.com/DanArmor)
 * @brief [Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
 * implementation in C
 * @details  The Game of Life, also known simply as Life.
 * It is a zero-player game, meaning that its evolution is determined by
 * its initial state, requiring no further input. One interacts with the Game of
 * Life by creating an initial configuration and observing how it evolves.
 * You can just run game - it will random generate init state, or write
 * your init state to file as a matrix of 0s and 1s of size 48x48. Lines can be
 * not completed as well as matrix. For example:
 * 00100
 * 01
 * 1
 * is a valid init state file. All 0s and not defined cells will be dead
 * at the start.
 * That version is using cycle grid - if cell "go" outside of grid to the right
 * - it will appear to the left side. Same for vertical direction.
 */

#include <stdio.h>   ///< for Standart Input Output
#include <stdlib.h>  ///< for random generation and exit function
#include <time.h>    ///< for get random generation seed as time(NULL)+clock()

/**
 * Choose correct header for "sleep" function depending on platform
 */
#ifdef _WIN32
#include <windows.h>
#else
#include <poll.h>  ///< we will use poll, cause usleep/etc is not always available
#endif

// Functions Declarations
static void initGrid(void);
static void randomGrid(void);
static void readInitFromFile(char *);
static void copyGridToPrev(void);
static int calcRowIndex(int i);
static int calcColIndex(int i);
static int countNeighbors(int, int);
static void updateGrid(void);
static void showGrid(void);
static void runGame(void);

// Size of game grid
#define MAX_ROWS 48
#define MAX_COLS 48
// Chars, that represents alive and dead cells
static const char deadChar = '0';
static const char aliveChar = '1';

/**
 * Current state of grid to draw
 */
static char currGrid[MAX_ROWS][MAX_COLS];
/**
 * Previous state of grid
 */
static char prevGrid[MAX_ROWS][MAX_COLS];

int main(int argc, char **argv)
{
    initGrid();
    // Check for valid number of args
    if (argc > 2)
    {
        fprintf(stderr, "Too many args\n");
        exit(1);
    }
    if (argc == 2)
    {
        readInitFromFile(argv[1]);
    }
    else
    {
        randomGrid();
    }
    runGame();
    return 0;
}

/**
 * @brief Initializes all cells as dead
 *
 * @returns None
 */
void initGrid(void)
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            currGrid[i][j] = deadChar;
        }
    }
}

/**
 * @brief Turns some cells to alive by random
 *
 * @returns None
 */
void randomGrid(void)
{
    srand(time(NULL) + clock());
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (rand() % 5 == 1)
            {
                currGrid[i][j] = aliveChar;
            }
        }
    }
}

/**
 * @brief Reads init state for Game Of Life from file with name fileName. Skips
 * all characters, besides of '\n', '0', '1'
 * @details if some line contains more, than 48 valid chars - it treated, as
 * more than one grid row writed in one line
 *
 * @param fileName name of input file
 * @returns None
 */
void readInitFromFile(char *fileName)
{
    FILE *f = fopen(fileName, "r");
    if (f == NULL)
    {
        fprintf(stderr, "File open error, fileName: %s\n", fileName);
        exit(1);
    }

    int currentRow = 0;
    int currentCol = 0;
    for (char c = fgetc(f); c != EOF; c = fgetc(f))
    {
        if (currentCol >= MAX_COLS)
        {
            currentRow++;
            currentCol = 0;
        }
        if (currentRow >= MAX_ROWS)
        {
            break;
        }

        if (c == aliveChar || c == deadChar)
        {
            currGrid[currentRow][currentCol] = c;
            currentCol++;
        }
        else if (c == '\n')
        {
            currentRow++;
            currentCol = 0;
        }
    }
}

/**
 * @brief Copes current grid to prevGrid
 * for purpose of further calculations
 *
 * @return None
 */
void copyGridToPrev(void)
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            prevGrid[i][j] = currGrid[i][j];
        }
    }
}

/**
 * @brief Calculates valid "on grid" position from given index,
 * that may be bigger then size of grid, or negative
 *
 * @param i index of row
 * @return valid row position in grid
 */
int calcRowIndex(int i)
{
    if (i < 0)
    {
        return MAX_ROWS - i;
    }
    else
    {
        return i % MAX_ROWS;
    }
}

/**
 * @brief Calculates valid "on grid" position from given index,
 * that may be bigger then size of grid, or negative
 *
 * @param i index of col
 * @return valid col position in grid
 */
int calcColIndex(int i)
{
    if (i < 0)
    {
        return MAX_COLS - i;
    }
    else
    {
        return i % MAX_COLS;
    }
}

/**
 * @brief Calculates amount of alive neighbors
 * of cell in 8 directions by given x,y coordinates
 *
 * @param x column position
 * @param y row position
 * @return amount of alive neighbors
 */
int countNeighbors(int x, int y)
{
    int aliveNeighbors = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }

            if (prevGrid[calcRowIndex(i + y)][calcColIndex(j + x)] == aliveChar)
            {
                aliveNeighbors++;
            }
        }
    }
    return aliveNeighbors;
}

/**
 * @brief Copes current state to prev state (prevGrid) and
 * calculates next state out of prev state and writes it
 * into currGrid
 *
 * @returns None
 */
void updateGrid(void)
{
    // Save current state as prev
    copyGridToPrev();
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            switch (countNeighbors(j, i))
            {
            case 2:
                if (prevGrid[i][j] == aliveChar)
                {
                    currGrid[i][j] = aliveChar;
                }
                break;
            case 3:
                currGrid[i][j] = aliveChar;
                break;
            default:
                currGrid[i][j] = deadChar;
                break;
            }
        }
    }
}

/**
 * @brief Outputs current state of grid
 *
 * @returns None
 */
void showGrid(void)
{
    // Escape-code for clean entire screen
    fputs("\033[2J", stdout);
    // Escape-code for setting cursor to "home" position
    fputs("\033[H", stdout);
    putchar('\n');
    fputs("    ", stdout);
    for (int i = 0; i < MAX_COLS * 2 + 3; i++)
    {
        putchar('*');
    }
    putchar('\n');

    for (int i = 0; i < MAX_ROWS; i++)
    {
        fputs("    * ", stdout);
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (currGrid[i][j] == aliveChar)
            {
                // Set output color to bright green
                fputs("\033[38;5;46m", stdout);
            }
            else
            {
                // Set output color to dark red
                fputs("\033[38;5;52m", stdout);
            }
            putchar('O');
            putchar(' ');
        }
        // Reset colors
        fputs("\033[0m", stdout);
        putchar('*');
        putchar('\n');
    }

    fputs("    ", stdout);
    for (int i = 0; i < MAX_COLS * 2 + 3; i++)
    {
        putchar('*');
    }

    fflush(stdout);
}

/**
 * @brief Endless game loop
 * @details 1. Output current state. 2.Calculate next state. 3. Wait for 400ms.
 * Go to 1
 * @returns None
 */
void runGame(void)
{
    while (1)
    {
        showGrid();
        updateGrid();
// Choose correct "sleep function". Sleep for 400 ms
#ifdef _WIN32
        Sleep(400);
#else
        poll(NULL, 0, 400);
#endif
    }
}

/**
 * @file game-of-life.c
 * @author [DanArmor](github.com/DanArmor)
 * @brief [Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)
 * implementation in C
 * @details  The Game of Life, also known simply as Life.
 * It is a zero-player game, meaning that its evolution is determined by
 * its initial state, requiring no further input. One interacts with the Game of
 * Life by creating an initial configuration and observing how it evolves.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <poll.h>
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
static char grid[MAX_ROWS][MAX_COLS];
/**
 * Previous state of grid
 */
static char prevGrid[MAX_ROWS][MAX_COLS];

int main(int argc, char **argv)
{
    initGrid();
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

void initGrid(void)
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            grid[i][j] = deadChar;
        }
    }
}

void randomGrid(void)
{
    srand(time(NULL) + clock());
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            if (rand() % 5 == 1)
            {
                grid[i][j] = aliveChar;
            }
        }
    }
}

/**
 * @brief
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
            currentCol = 0;
            currentRow++;
        }
        if (currentRow >= MAX_ROWS)
        {
            break;
        }

        if (c == aliveChar || c == deadChar)
        {
            grid[currentRow][currentCol] = c;
            currentCol++;
        }
        else if (c == '\n')
        {
            currentRow++;
            currentCol = 0;
        }
    }
}

void copyGridToPrev(void)
{
    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            prevGrid[i][j] = grid[i][j];
        }
    }
}

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

void updateGrid(void)
{
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
                    grid[i][j] = aliveChar;
                }
                break;
            case 3:
                grid[i][j] = aliveChar;
                break;
            default:
                grid[i][j] = deadChar;
                break;
            }
        }
    }
}

void showGrid(void)
{
    fputs("\033[2J", stdout);
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
            if (grid[i][j] == aliveChar)
            {
                fputs("\033[38;5;46m", stdout);
            }
            else
            {
                fputs("\033[38;5;52m", stdout);
            }
            putchar('O');
            putchar(' ');
        }
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

void runGame(void)
{
    while (1)
    {
        showGrid();
        updateGrid();
#ifdef _WIN32
        Sleep(500);
#else
        poll(NULL, 0, 400);
#endif
    }
}

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

// Functions Declarations
static void initGrid(void);
static void createGridFromFile(char *);
static void runGame(void);

// Size of game grid
static const int maxRows = 32;
static const int maxCols = 32;
// Chars, that represents alive and dead cells
static const char deadChar = '0';
static const char aliveChar = '1';

/**
 * Current state of grid to draw
 */
static char grid[maxRows][maxCols];
/**
 * Previous state of grid
 */
static char prevGrid[maxRows][maxCols];

int main(int argc, char **argv)
{
    initGrid();
    if (argc > 2)
    {
        fprintf(stderr, "Too many args");
        exit(1);
    }
    if (argc == 2)
    {
        readInitFromFile(argv[1]);
    }
    runGame();
    return 0;
}

void initGrid(void)
{
    for (int i = 0; i < maxRows; i++)
    {
        for (int j = 0; j < maxCols; j++)
        {
            grid[i][j] = deadChar;
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
        if (currentCol >= maxCols)
        {
            currentCol = 0;
            currentRow++;
        }
        if (currentRow >= maxRows)
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
        }
    }
}

/*
I walk  through the grids and record the path numbers at the
same time.
By using a 2D array called paths, it will add up possible so
urce path and save the number.
Noted that:
if  the  destination has   obstacle,   we  can't    reach it
the first  grid  (paths[0][0]) always  set  as 1    our  previous
path source  is    either  from top   or left  border of grid has
different condition
*/

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize,
                             int* obstacleGridColSize)
{
    if (obstacleGrid[obstacleGridSize - 1][*obstacleGridColSize - 1] == 1)
    {
        return 0;
    }
    int paths[obstacleGridSize][*obstacleGridColSize];
    for (int i = 0; i < obstacleGridSize; i++)
    {
        for (int j = 0; j < *obstacleGridColSize; j++)
        {
            if (obstacleGrid[i][j])
            {
                paths[i][j] = 0;
            }
            else
            {
                paths[i][j] = (i == 0 && j == 0)
                                  ? 1
                                  : ((i == 0 ? 0 : paths[i - 1][j]) +
                                     (j == 0 ? 0 : paths[i][j - 1]));
            }
        }
    }
    return paths[obstacleGridSize - 1][*obstacleGridColSize - 1];
}

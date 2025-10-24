int numRookCaptures(char** board, int boardSize, int* boardColSize) {
    int attack = 0;
    int x = 0;
    int y = 0;

    //Find the Rook's position on the board
    for(int i = 0;i<8;i++)
    {
        for(int j = 0;j<8;j++)
        {
            if(board[i][j] == 'R')
            {
                x = i;
                y = j;
                break;
            }
        }
    }
    //DOWN
    for(int i = x+1;i<8;i++)
    {
        if(board[i][y] != '.')
        {
            if(board[i][y] == 'p')
            {
                attack++;
            }
            break;
        }
    }
    //UP
    for(int i = x-1;i>=0;i--)
    {
        if(board[i][y] != '.')
        {
            if(board[i][y] == 'p')
            {
                attack++;
            }
            break;
        }
    }
    //LEFT
    for(int j = y-1;j>=0;j--)
    {
        if(board[x][j] != '.')
        {
            if(board[x][j] == 'p')
            {
                attack++;
            }
            break;
        }
    }
    //RIGHT
    for(int j = y+1;j<8;j++)
    {
        if(board[x][j] != '.')
        {
            if(board[x][j] == 'p')
            {
                attack++;
            }
            break;
        }
    }
    return attack;
}

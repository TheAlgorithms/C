int** initSet(int size){
    int** result = (int**) malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        result[i] = (int*)calloc(size, sizeof(int));
    }
    
    return result;    
}

// Returns the id of triplet which the point (i, j) belongs to
int getTripletId(int i, int j){
    return (i / 3) * 3 + (j / 3);
}

// Recursive function which populates sudoku board.
bool sudokuSolver(int startI, int startJ, char** board, int boardSize, int* boardColSize, int** horizontalsSets, int** verticalsSets, int** tripletsSets){
    for (int i = startI; i < boardSize; i++) {
        for (int j = startJ; j < boardColSize[i]; j++) {
            if (board[i][j] != '.'){
                continue;
            }
            
            // Find the sets of the current point (i, j)
            int* horizontalSet = horizontalsSets[i];
            int* verticalSet = verticalsSets[j];
            int* tripletsSet = tripletsSets[getTripletId(i, j)];
            
            for (int z = 1; z < 10; z++) {
                if (horizontalSet[z] || verticalSet[z] || tripletsSet[z]){
                    continue;
                }
                
                // If the z doesn't belong to occupations sets, we check this value to be in place
                horizontalSet[z] = 1;
                verticalSet[z] = 1;
                tripletsSet[z] = 1;
                
                if (sudokuSolver(i, j + 1, board, boardSize, boardColSize, horizontalsSets, verticalsSets, tripletsSets)){
                    board[i][j] = z + '0';
                    return true;
                }
                
                horizontalSet[z] = 0;
                verticalSet[z] = 0;
                tripletsSet[z] = 0;
            }
            
            // We tried all possible values in range 1-10. No variants - returns false;
            return false;
        }

        // startJ to begin of the row.
        startJ = 0;
    }
    
    // Reach it when the end of the board - then all previous values are setup correctly.
    return true;
}

// Use backtracking
void solveSudoku(char** board, int boardSize, int* boardColSize){
    // Declare sets for cheking occupation of numbers by horizontals, verticals lines and triplets.
    int** horizontalsSets = initSet(boardSize + 1);
    int** verticalsSets = initSet(boardSize + 1);
    int** tripletsSets = initSet(getTripletId(boardSize + 1, boardSize + 1));

    // Populate sets with values from the board.
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == '.'){
                continue;
            }
            
            int value = board[i][j] - '0';
            horizontalsSets[i][value] = 1;
            verticalsSets[j][value] = 1;
            tripletsSets[getTripletId(i, j)][value] = 1;
        }
    }

    // Solving
    sudokuSolver(0, 0, board, boardSize, boardColSize, horizontalsSets, verticalsSets, tripletsSets);

    // Free resources
    free(horizontalsSets);
    free(verticalsSets);
    free(tripletsSets);
}

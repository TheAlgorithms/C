int getPointKey(int i, int j, int boardSize, int boardColSize){
    return boardSize * boardColSize * i + j;
}

const int directionsSize = 4;
const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool exitsWord(int i, int j, char** board, int boardSize, int* boardColSize, int wordIndex, char* word, int* vistedPointSet){
    if (board[i][j] != word[wordIndex]){
        return false;
    }
    
    if (wordIndex == strlen(word) - 1){
        return true;
    }
    
    for (int k = 0; k < directionsSize; k++){
        int nextI = i + directions[k][0];
        int nextJ = j + directions[k][1];
        
        if (nextI < 0 || nextI >= boardSize || nextJ < 0 || nextJ >= boardColSize[i]){
            continue;
        }
        
        int key = getPointKey(nextI, nextJ, boardSize, boardColSize[i]);
        if (vistedPointSet[key] == 1){
            continue;
        }
        
        vistedPointSet[key] = 1;
        if (exitsWord(nextI, nextJ, board, boardSize, boardColSize, wordIndex + 1, word, vistedPointSet)){
            return true;
        }

        vistedPointSet[key] = 0;
    }
    
    return false;
}


// Use backtracking.
// Runtime: Runtime: O(n*m*4^len(word))
bool exist(char** board, int boardSize, int* boardColSize, char* word){
    int* vistedPointSet = (int*) calloc(getPointKey(boardSize, boardColSize[0], boardSize, boardColSize[0]), sizeof(int));

    for (int i = 0; i < boardSize; i++){
        for (int j = 0; j < boardColSize[i]; j++){
            int key = getPointKey(i, j, boardSize, boardColSize[i]);
            vistedPointSet[key] = 1;
            if (exitsWord(i, j, board, boardSize, boardColSize, 0, word, vistedPointSet)){
                return true;
            };
            
            vistedPointSet[key] = 0;
        }
    }
    
    return false;
}

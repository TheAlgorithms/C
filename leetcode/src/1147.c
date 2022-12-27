#define max(a,b) (((a)>(b))?(a):(b))

bool equalSubstrings(char* text, int firstIndex, int secondIndex, int length){
    for (int i = 0; i < length; i++){
        if (text[firstIndex + i] != text[secondIndex + i]){
            return false;
        }
    }

    return true;
}

int longestDecompositionDpCached(char* text, int textLen, int index, int* dp){
    if (2 * index >= textLen){
        return 0;
    }

    if (dp[index] == 0){
        dp[index] = longestDecompositionDp(text, textLen, index, dp);
    }

    return dp[index];
}

int longestDecompositionDp(char* text, int textLen, int index, int* dp){
    char ch = text[index];
    int result = 1;
    
    for (int i = 0; i < (textLen - 2 * index) / 2; i++){
        if (ch == text[textLen - 1 - index - i] 
            && equalSubstrings(text, index, textLen - 1 - index - i, i + 1)){
                return max(result, 2 + longestDecompositionDpCached(text, textLen, index + i + 1, dp));
        }
    }

    return result;
}

// Dynamic programming. Up -> down approach.
// Runtime: O(n*n)
// Space: O(n)
int longestDecomposition(char * text){
    int textLen = strlen(text);
    int* dp = calloc(textLen, sizeof(int));
    int result = longestDecompositionDpCached(text, textLen, 0, dp);

    free(dp);
    return result;
}

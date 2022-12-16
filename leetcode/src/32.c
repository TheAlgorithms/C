#define max(x,y)(((x)>(y))?(x):(y))

const int notCalculated = -2;
const int notValid = -1;

int getEndValidIndexFromDp(int* dp, char* s, int index, int lenS){
    if (index >= lenS){
        return notValid;
    }

    if (dp[index] == notCalculated){
        dp[index] = getEndValidIndex(dp, s, index, lenS);
    }

    return dp[index];
}

int getEndValidIndex(int* dp, char* s, int index, int lenS){
    if (s[index] == '('){
        if (index + 1 >= lenS){
            return notValid;
        }

        if (s[index + 1] == ')'){
            return max(index + 1, getEndValidIndexFromDp(dp, s, index + 2, lenS));
        }
        
        int nextEndValidIndex = getEndValidIndexFromDp(dp, s, index + 1, lenS);
        if (nextEndValidIndex == notValid || nextEndValidIndex + 1 >= lenS || s[nextEndValidIndex + 1] != ')') {
            return notValid;
        }
        
        return max(nextEndValidIndex + 1, getEndValidIndexFromDp(dp, s, nextEndValidIndex + 2, lenS));
    }
    
    return notValid;
}

// Dynamic Programming. UP -> down approach.
// Runtime: O(n)
// Space: O(n)
int longestValidParentheses(char * s){
    int lenS = strlen(s);
    if (lenS == 0){
        return 0;
    }

    int* dp = malloc(lenS * sizeof(int));
    for(int i = 0; i < lenS; i++){
        dp[i] = notCalculated;
    }

    int result = 0;
    for(int i = 0; i < lenS; i++){
        result = max(result, getEndValidIndexFromDp(dp, s, i, lenS) - i + 1);
    }
    
    free(dp);
    return result;
}

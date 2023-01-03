#define max(X, Y) ((X) > (Y) ? (X) : (Y))

int maximizeTarget(char * answerKey, char targetChar, int k){
    int leftIndex = -1;
    int result = 0;
    int currTargetChars = 0;
    int lenAnswerKey = strlen(answerKey);

    for (int rightIndex = 0; rightIndex < lenAnswerKey; rightIndex++){
        char ch = answerKey[rightIndex];
        if (ch == targetChar){
            currTargetChars++;
        }
        
        while (rightIndex - leftIndex > currTargetChars + k) {
            leftIndex++;
            if (answerKey[leftIndex] == targetChar){
                currTargetChars--;
            }
        }
        
        result = max(result, rightIndex - leftIndex);
    }
    
    return result;
}

// Use sliding window approach + two pointers.
// Runtime: O(n)
// Space: O(1)
int maxConsecutiveAnswers(char * answerKey, int k){
    return max(maximizeTarget(answerKey, 'T', k), maximizeTarget(answerKey, 'F', k));
}

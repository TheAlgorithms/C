#define min(x, y) (((x) < (y)) ? (x) : (y))

bool isWordLess(char* word1, char* word2, int* charOrder){
    int word1Length = strlen(word1);
    int word2Length = strlen(word2);
    
    for(int i = 0; i < min(word1Length, word2Length); i++) {
        int charWordsDiff = (charOrder[word1[i] - 'a'] - charOrder[word2[i] - 'a']);

        if (charWordsDiff < 0){
            return true;
        }

        if (charWordsDiff > 0){
            return false;
        }
    }
    
    return word1Length <= word2Length;
}

// Keep array-hashtable of order letters.
// Runtime: O(n)
// Space: O(1)
bool isAlienSorted(char ** words, int wordsSize, char * order){
    const int lowerCaseLettersNumber = 26;
    int charorder[lowerCaseLettersNumber];

    for(int i = 0; i < lowerCaseLettersNumber; i++) {
        charorder[order[i] - 'a'] = i;
    }

    for(int i = 0; i < wordsSize - 1; i++) {
        if (!isWordLess(words[i], words[i + 1], charorder)){
            return false;
        }
    }

    return true;
}

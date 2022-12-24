const charLength = 26;

int* charsCount(char* word){
    int* result = calloc(charLength, sizeof(int));
    int wordLen = strlen(word);
    for (int i = 0; i < wordLen; i++){
        result[word[i] - 'a']++;
    }

    return result;
}

int diff (const int *i, const int *j)
{
    return *i - *j;
}

// Counting
// Runtime: O(n)
// Space: O(1)
bool closeStrings(char * word1, char * word2){
    int* word1CharsCounter = charsCount(word1);
    int* word2CharsCounter = charsCount(word2);

    if (strlen(word1) != strlen(word2)){
        return false;
    }

    for (int i = 0; i < charLength; i++){
        if ((word1CharsCounter[i] != 0 && word2CharsCounter[i] == 0) ||
           (word1CharsCounter[i] == 0 && word2CharsCounter[i] != 0)){
               return false;
           }
    }

    qsort(word1CharsCounter, charLength, sizeof (int), (int(*) (const void *, const void *)) diff);
    qsort(word2CharsCounter, charLength, sizeof (int), (int(*) (const void *, const void *)) diff);

    for (int i = 0; i < charLength; i++){
        if (word1CharsCounter[i] != word2CharsCounter[i]){
               return false;
        }
    }

    free(word1CharsCounter);
    free(word2CharsCounter);
    return true;
}

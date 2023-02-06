const int EnglishLettersNumber = 26;

void countCharsForStringSlice(int* charsCounter, char* s, int length, int sign) {
    for (int i = 0; i < length; i++) {

        charsCounter[s[i] - 'a'] += sign;
    }
}

// Sliding window
// Calculate number of chars in the current slide. 
// Runtime: O(n)
// Space: O(1) - only number of english lowercase letters.
bool checkInclusion(char* s1, char* s2) {
    int lengthS1 = strlen(s1);
    int lengthS2 = strlen(s2);

    if (lengthS1 > lengthS2) {

        return false;
    }

    int* charsCounter = calloc(EnglishLettersNumber, sizeof(int));

    // We keep counters of s1 with '-' sign. It has to be offset by s2 chars
    countCharsForStringSlice(charsCounter, s1, lengthS1, -1);
    countCharsForStringSlice(charsCounter, s2, lengthS1, 1);

    int diffChars = 0;
    for (int i = 0; i < EnglishLettersNumber; i++) {
        if (charsCounter[i] != 0) {
            diffChars++;
        }
    }

    if (diffChars == 0) {
        return true;
    }

    for (int i = 0; i < lengthS2 - lengthS1; i++) {
        int charNumberLeft = s2[i] - 'a';
        int charNumberRight = s2[i + lengthS1] - 'a'; 

        charsCounter[charNumberLeft] -= 1;
        if (charsCounter[charNumberLeft] == 0) {
            diffChars -= 1;
        }
        else if (charsCounter[charNumberLeft] == -1) {
            diffChars += 1;
        }

        charsCounter[charNumberRight] += 1;
        if (charsCounter[charNumberRight] == 0) {
            diffChars -= 1;
        }
        else if (charsCounter[charNumberRight] == 1) {
            diffChars += 1;
        }

        if (diffChars == 0) {
            return true;
        }
    }

    free(charsCounter);
    return false;
}

bool isVowel(char chr){
    switch(chr){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
    }
    
    return false;
}

// Counting
// Runtime: O(n)
// Space: O(1)
bool halvesAreAlike(char * s){
    int lenS = strlen(s);
    int halfVowels = 0;
    int currVowels = 0;
    
    for (int i = 0; i < lenS; i++){
        if (isVowel(s[i])){
            currVowels++;
        }
        
        if (2 * (i + 1) == lenS){
            halfVowels = currVowels;
        }
    }
    
    return 2 * halfVowels == currVowels;
}

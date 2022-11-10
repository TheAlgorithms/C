long long numberOfWaysForChar(char * s, char c){
    long firstItemsNumber = 0;
    long secondItemsNumber = 0;
    long result = 0;
    
    int sLength = strlen(s);
    for (int i = 0; i < sLength; i++){
        if (s[i] == c){
            result += secondItemsNumber;

            firstItemsNumber += 1;
            continue;
        }

        secondItemsNumber += firstItemsNumber;
    }
    
    return result;
        
}

// Counting: Calculating sum of first ways of building. Then plus it to second and calculate with third.
// Runtime: O(n)
// Space: O(n)
long long numberOfWays(char * s){
    return numberOfWaysForChar(s, '0') + numberOfWaysForChar(s, '1');
}

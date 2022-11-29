long numberOfWaysForChar(char * s, char c){
    long firstBuildingAppearNumber = 0;
    long secondBuildingAppearNumber = 0;
    long result = 0;
    
    int sLength = strlen(s);
    for (int i = 0; i < sLength; i++){
        if (s[i] == c){
            result += secondBuildingAppearNumber;

            firstBuildingAppearNumber += 1;
            continue;
        }

        secondBuildingAppearNumber += firstBuildingAppearNumber;
    }
    
    return result;
        
}

// numberOfWays returns the sum of number ways of selecting first building
// and the number of ways of selecting second building which gives us the
// number of ways of selecting three building such that no
// consecutive buildings are in the same category.
// Runtime: O(n)
// Space: O(n)
long long numberOfWays(char * s){
    return numberOfWaysForChar(s, '0') + numberOfWaysForChar(s, '1');
}

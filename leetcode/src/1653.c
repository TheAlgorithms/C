#define min(X, Y)  ((X) < (Y) ? (X) : (Y))
#define getBoolToInt(VAL)  (VAL ? (1) : (0))

// Dynamic programming approach. Down -> Up.
// Runtime: O(n)
// Space: O(1)
int minimumDeletions(char * s){
    int len = strlen(s);
    
    int aStateValue = s[0] == 'b';

    int bStateValue = 0;
    
    int newAStateValue;
    int newBStateValue;

    for(int i = 1; i < len; i++){
        newAStateValue = aStateValue + (s[i] == 'b');

        newBStateValue = min(
                               aStateValue,
                               bStateValue + getBoolToInt(s[i] == 'a')
                             );
            
        aStateValue = newAStateValue;
        bStateValue = newBStateValue;
    }
    
    return min(aStateValue, bStateValue);
}

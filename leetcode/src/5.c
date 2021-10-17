/* Find the longest palindrome substring in the given string

Example:
Input: abdfghjhgfdty
Output: dfghjhgfd

Input : afrtyuiop
Output: a

The logic of this program is that we will decide on one index and 
expand on both sides till the end of the string is reached or till 
the characters at the boundaries don't match. This will be done for
each character in the string to find the longest palindromic substring 
*/

/* This function will expand on both sides from given center till it finds 
a mismatch or till it reaches either end of the string 
@param s - the string whose longest palindromic substring has to be calculated
@param i - a pointer indicating the left boundary of the substring
@param j - a pointer indicating the right boundary of the substring
@param n - the length of the string
@returns the length of the longest palindromic substring
*/

int find_longest_palindrome(char *s, int i, int j, int n) {
    int c = 0; // the length of the largest palindrome 
    
    /* the terminating conditions for finding the palindrome are if 
    we reach either end (i.e., i < 0 or j == n) or if the characters 
    at the current pointers are not equal (then it wouldn't be a palindrome) */ 
    while (i >= 0 && j < n && s[i] == s[j]) { 
        i--;
        j++;
        c++;
    }
    
    return c;
}

/* A function which will return the longest palindromic substring
@param s - the string whose longest palindromic substring has to be calculated
@returns the longest palindromic substring*/
char * longestPalindrome(char * s){
    int length = 0;  // A variable to store the length of the longest substring found 
    int start_pos = 0; // A variable to store the starting position of the longest substring found
    int n = strlen(s); // A variable to store the length of the string 
    int cur_len = 0; // A variable to store the length of the longest substring at current index
    
    // loop for each character and expand 
    for (int i = 0; i < n; i++) {
        cur_len = find_longest_palindrome(s, i, i, n); // This is to find the longest palindrome of odd length. 
        
        // As the palindrome is odd length, the expansion would give a substring of length 2*cur_len - 1
        if (length < (2*cur_len - 1)) {
            length = 2*cur_len - 1;
            start_pos = i - cur_len + 1;
        }    
    
        cur_len = find_longest_palindrome(s, i, i+1, n); // Expand for finding the longest palindrome of even length
        
        // As the palindrome is even length, the expansion would give a substring of length 2*cur_len
        if (length < (2*cur_len)) {
            length = 2*cur_len;
            start_pos = i - cur_len + 1;
        }
    }
    
    // return the substring
    s[start_pos + length] = '\0';
    return s + start_pos;
}

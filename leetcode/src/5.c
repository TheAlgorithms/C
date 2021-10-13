int find_longest_palindrome(char *s, int i, int j, int n) {
    int c = 0;
    
    while (i >= 0 && j < n && s[i] == s[j]) {
        i--;
        j++;
        c++;
    }
    
    return c;
}

char * longestPalindrome(char * s){
    int length = 0;
    int start_pos = 0;
    int n = strlen(s);
    int cur_len = 0;
    
    for (int i = 0; i < n; i++) {
        cur_len = find_longest_palindrome(s, i, i, n);
        
        if (length < (2*cur_len - 1)) {
            length = 2*cur_len - 1;
            start_pos = i - cur_len + 1;
        }
        
        cur_len = find_longest_palindrome(s, i, i+1, n);
        
        if (length < (2*cur_len)) {
            length = 2*cur_len;
            start_pos = i - cur_len + 1;
        }
    }
    
    s[start_pos + length] = '\0';
    return s + start_pos;
}

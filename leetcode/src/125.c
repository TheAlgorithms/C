bool isPalindrome(char * s){
    int start = 0, end = strlen(s) - 1;
    while(start < end) {
        if (!isalpha(s[start]) && !isalnum(s[start])) {
            start++;
        }
        else if (!isalpha(s[end]) && !isalnum(s[end])) {
            end--;
        } else {
            char c1 = tolower(s[start]);
            char c2 = tolower(s[end]);
            if(c1 != c2)
                return 0;
            start++;
            end--;
        }
    }
    return 1;
}

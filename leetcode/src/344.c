void reverseString(char* s, int sSize){
    int last = sSize - 1, i;
    for (i = 0; i < last; i++) {
        char tmp = s[i];
        s[i] = s[last];
        s[last] = tmp;
        last--;
    }

}

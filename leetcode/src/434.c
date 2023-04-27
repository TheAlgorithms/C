// Given a string s, returns the number of segments in the string.
int countSegments(char *s) {
    int i, l = strlen(s), segments = 0;
    if (l == 0) { // Return early for empty string
        return 0;
    }

    for (i = 0; i < l; i++) {
        if (s[i] != ' ') {
            break; // Skip to first non-space character
        }
    }

    //Start from the first non-space character index, calculated above
    for (; i < l;) {
        while (i < l && s[i] != ' ') { // Iterate till current character is not a space
           i++;
        } 
        //We hit a space, so increment count
        segments++;
        while (i < l && s[i] == ' ') { //Skip consecutive spaces
            i++;
        }
    }

    return segments;
}

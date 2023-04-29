// Given a string s, returns the number of segments in the string.
int countSegments(char * s){
    int sLen = strlen(s);
    int prevSpace = 1;
    int result = 0;
    char currChar;

    for (int i = 0; i < sLen; i++){
        currChar = s[i];

        //A string of whitespaces will only be counted once as the condition below is only true when we transition from whitespace to non-whitespace.
        //Since we start with assumed whitespace (prevSpace = 1), initial whitespaces are handled as well, if any
        if (s[i] != ' ' && prevSpace) {
            result++;
        }
        prevSpace = (currChar == ' ');
    }

    return result;
}

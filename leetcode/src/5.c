/* Approach #1 */
int checkPalindrome(char *s, int start, int end) {
    for(int k = 1; k <= (end-start)/2; k++) {
        if(*(s + start + k) != *(s + end - k))
            return 0;
    }
    return 1;
}

char * longestPalindrome(char * s){
	char *result = NULL;
	int strSize = strlen(s);
	int start = 0;
	int end = 0;
	int largest = 0;
	for(int i = 0; i < strSize; i++){
		for(int j = i + largest; j < strSize; j++){
			if(*(s+i) == *(s+j)){
				int pass = checkPalindrome(s, i, j);
				if(pass && largest < j-i+1){
					largest = j - i + 1;
					start = i;
					end = j;
				}
			}
		}
	}
	result = (s+start);
	// Destructive
	if(largest > 0 && end+1 != strSize+1){
		s[end+1] = '\0';
	}
	return result;
}

/* Alternative approach */
int maxVal(int a, int b) {
    return a > b ? a : b;
}

int extend(char *s, int start, int end) {
    int len = strlen(s);
    for(; start >= 0 && end < len; start--, end++) {
        if(*(s + start) != *(s + end))
            break;
    }
    return end - start - 1;
}

char * longestPalindrome(char * s){
    int max = 0, idx = 0, len = strlen(s);
    for(int i = 0; i < len; i++) {
        int len1 = extend(s, i, i);       /* For even string */
        int len2 = extend(s, i, i + 1);   /* For odd string  */
        if (max < maxVal(len1, len2)) {
            idx = (len1 > len2) ? (i - len1 / 2) : (i - len2 / 2 + 1);
            max = maxVal(len1, len2);
        }
    }
    char *res = malloc((max+1) *sizeof(char));
    memcpy(res, &s[idx], max);
    res[max] = '\0';
    return res;
}

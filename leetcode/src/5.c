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

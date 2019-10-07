char * longestPalindrome(char * s){
	char *result = NULL;
	int strSize = strlen(s);
	int start = 0;
	int end = 0;
	int largest = 0;
	for(int i = 0; i < strSize; i++){
		for(int j = i + largest; j < strSize; j++){
			if(*(s+i) == *(s+j)){
				int pass = 1;
				for(int k = 1; k <= (j-i)/2; k++){
					if(*(s+i+k) != *(s+j-k)){
						pass = 0;						
						break;
					}
				}
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

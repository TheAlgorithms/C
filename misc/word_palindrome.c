/**
 * @file
 * @brief Check if a given word or phrase is a palindrome.
 * @details
 * A palindrome is a word, number, phrase, or other sequence of 
 * characters which reads the same backward as forward, such as
 * madam, racecar.
 * This program will be able to check phrases, with words 
 * separated by spaces, but can't deal with special characters.
 * @author [Maria Eduarda Kawakami](https://github.com/madukm)
 *
 */

#include <stdlib.h> //for malloc and free
#include <assert.h> //for assert
#include <string.h> //for strlen 
#include <ctype.h> //for tolower

/**
 * @brief Check is a string is a palindrome.
 * @param str string to check
 * @returns 0 if it's not a palindrome
 * @returns 1 if it's a palindrome
 *
 */
int isPalindrome(char str[])
{
	int i = 0, j, size = 0;
	while(str[i++] != '\0') size++; 

	char *temp;
	temp = (char *)malloc((size+1)*sizeof(char));

	j = 0;
	for(i=0; i<size; i++){
		if(str[i] != ' '){
			temp[j++] = tolower(str[i]);	
		}
	}
	temp[j] = '\0';
	size = j;
   
	for(i=0, j=size-1; j>=i; i++, j--)
	{
        if(temp[i] != temp[j]){
			free(temp);
			return 0;
		}
    }
	free(temp);
   	return 1;
}

/**
 * @brief Test function
 * @returns void
 */
static void test(){
	assert(isPalindrome("arara"));
	assert(isPalindrome("madam"));
	assert(isPalindrome("Able was I ere I saw Elba"));
	assert(!isPalindrome("Ilikeoranges"));
	assert(!isPalindrome("Hacktoberfest"));
}

/**
 * @brief Main function
 * @param argc commandline argument count (ignored)
 * @param argv commandline array of arguments (ignored)
 * @returns
 */
int main(int argc, char *argv[])
{
    
	test();
    
	return 0;
}

/**
 * @file
 * @author [Santosh Jonnakuti](https://github.com/Santoshjonnakuti)
 * @brief [Longest Common Subsequence Algorithm](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem)
 * implementation in C to find the LCS between 2 strings.
 * @details LCS algorithm uses dynamic programming approach to find all possible LCS between 2 strings. 
 * Dynamic Programming follow a method so that even sub-problems will also have optimal solution.
 *
 * LCS() will find the length of the LCS of the following two strings 'GAC' and 'AGCAT'.
 * LCS function will return the following 2D-Matrix
 *
 *      0 0 0 0 0 0
 *      0 0 1 1 1 1
 *      0 1 1 1 2 2
 *      0 1 1 2 2 2
 *
 * So Length of LCS will be 2.
 *
 * allPossibleLSC() will print all possible LCS between those strings.
 *
 * AC
 * GC
 * GA
 * GA
 * 
 * To test run './longest_common_subsequence -test'
 * So There are 4 Longest common subsequences in 'GAC' and 'AGCAT'
 */


#include <stdio.h>      /// for I/O operations
#include <stdlib.h>     /// for dynamic memory allocation
#include <string.h>     /// for `puts()`, `gets()`, and `strlen()`
#include <assert.h>     /// for `assert()`

#define MAX 100      // maximum size of string1 and string2

/**
 * @brief Structure to store all LCS and no of possible LCS
 */
struct array
{
	char **LCSArray;      // array to store all possible LCS
	int length;           // no of possible LCs
} variable;


// Functions Declaration
int max(int a, int b);
int** LCS(char *string1, int m, char *string2, int n);
void allPossibleLCS(int **c, char *a, int index, int i, int j, char *string1, char *string2, int lengthOfLCS);
void findAllLCS(char *string1, char *string2);
static void test();

/**
 * @brief prints all possible Longest common subsequences between string1 and string2 using recursion
 * @param c 2D-Array of Optimal solutions of all sub-problems
 * @param a Longest common subsequence 
 * @param index  length of a
 * @param i length of string 1
 * @param j length of string 2
 * @param string1 String 1
 * @param string2 String 2
 * @prints one of the Longest Common Subsequence
 * @returns void
 */
void allPossibleLCS(int **c, char *a, int index, int i, int j, char *string1, char *string2, int lengthOfLCS)
{
	// If either i is 0 or j is 0  then there will be no LCS
	while(i > 0 && j > 0)
	{
		// Comparing chars at index j-1 of string2 and index i-1 of string1 because indexing of strings starts from 0
		// If Matched
		if(string2[j-1] == string1[i-1])
		{
			a[index] = string2[j-1];
			index++;
			i--;
			j--;
		}
		// If not matched
		else
		{	
			if(c[i-1][j] > c[i][j-1])
			{
				i--;
			}
			else if(c[i-1][j] == c[i][j-1])
			{
				allPossibleLCS(c, a, index, i, j-1, string1, string2, lengthOfLCS);
				i--;
			}
			else
			{
				j--;
			}
		}
	}
	// if LCSArray is NULL then allocating a memory to store LCS
	char **LCSArray = variable.LCSArray;
	if(LCSArray == NULL)
	{
		LCSArray = (char **)calloc(1, sizeof(char *));
		*(LCSArray + variable.length) = (char *)calloc(lengthOfLCS, sizeof(char));
		for(int k=lengthOfLCS-1; k >= 0; k--)
		{
			LCSArray[variable.length][lengthOfLCS-k-1] = a[k];
		}
	}
	// if not NULL then reallocating to store one more LCS
	else
	{
		LCSArray = (char **)realloc(LCSArray, (variable.length + 2)*sizeof(char *));
		variable.length += 1;
		*(LCSArray + variable.length) = (char *)calloc(lengthOfLCS, sizeof(char));
		for(int k=lengthOfLCS-1; k >= 0; k--)
		{
			LCSArray[variable.length][lengthOfLCS-k-1] = a[k];
		}
	}
	variable.LCSArray = LCSArray;
	return;
}

/**
 * @brief max will find the maximum between 2 values
 * @param a integer a
 * @param b integer b
 * @returns maximum value
 */
int max(int a, int b)
{
	// if a is greater than b return a
	if(a > b)
	{
		return a;
	}
	// else return b
	return b;
}

/**
 * @brief LCS will make 2D-array with optimal solutions of sub-problems
 * @param string1 String 1
 * @param m Length of String 1
 * @param string2 String 2
 * @param n Length of String 2
 * @returns 2D-array
 */
int** LCS(char *string1,int m, char *string2, int n)
{
	// Creating a 2D-array to store the solutions of all sub-problems
	int **c;
	
	// Dynamically allocating memory for 2D-array
	c = (int **)calloc(m+1, sizeof(int *));
	for(int i=0; i<=m; i++)
	{
		*(c + i) = (int *)calloc(n+1, sizeof(int));
	}
	// c[i][j] will have the length of Longest common subsequence when length of string 1 is i and length of string 2 is j
	
	// If length of string 2 is 0 then there will be no Longest common subsequence
	for(int i=1; i<=m; i++)
	{
		c[i][0] = 0;
	}
	
	// If length of string 1 is 0 then there will be no Longest common subsequence
	for(int j=0; j <=n; j++)
	{
		c[0][j] = 0;
	}
	
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			// If string1[i] == string2[j]
			if(string1[i] == string2[j])
			{
				c[i+1][j+1] = c[i][j]+1;
			}
			// If string1[i] != string2[j]
			else
			{
				c[i+1][j+1] = max(c[i][j+1], c[i+1][j]);
			}
		}
	}
	return c;
}

/**
 * @brief findAllLCS is to print all possible LCS
 * @param string1 string 1
 * @param string2 string 2
 * @returns void
 */
void findAllLCS(char *string1, char *string2)
{
	// lengths of two Strings;
	int lenOfStr1 = strlen(string1);       /// length of string1
	int lenOfStr2 = strlen(string2);       /// length of string2

	// if length of any string is 0 then there will be no LCS
	if(lenOfStr1 == 0 || lenOfStr2 == 0)
	{
		printf("There is no Possible Longest Common Subsequence...\n\n");
		return;
	}
	int** c = LCS(string1, lenOfStr1, string2, lenOfStr2);   /// To make the 2D-Array
	int lengthOfLCS = c[strlen(string1)][strlen(string2)];   /// Length of LCS
	printf("Length of Longest Common Subsequence is %d...\n\n", lengthOfLCS);

	// Character Array to store Longest common subsequence
	char a[lengthOfLCS];
	int index=0;
	
	// If there is no Longest common subsequence
	if (!lengthOfLCS)
	{
		printf("There is no Possible LCS...\n\n");
		return;
	}

	// If there is/are  Longest common subsequence then printing them
	printf("All Possible LCS are : \n\n");

    
	allPossibleLCS(c, a, index, lenOfStr1, lenOfStr2, string1, string2, lengthOfLCS);

	printf("Printing from the LCSArray\n\n\n");
	char **LCSArray = variable.LCSArray;
	for(int i=0; i<=variable.length; i++)
	{
		for(int j=0; j<lengthOfLCS; j++)
		{
			printf("%c", LCSArray[i][j]);
		}
		printf("\n");
	}
	free(c);
	free(string1);
	free(string2);
	LCSArray = NULL;
	free(LCSArray);
	return;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
	char string1[] = "GAC";
	char string2[] = "AGCAT";
	findAllLCS(string1, string2);
	char **LCSArray = variable.LCSArray;
	// Solutions of test input
	char solutions[][2] = {"AC", "GC", "GA", "GA"};

	// To assert the solutions
	for(int i=0; i<=variable.length; i++)
	{
		for(int j=0; j < 2; j++)
		{
			assert(LCSArray[i][j] == solutions[i][j]);
		}
        
	}
	return;
}
/**
 * @brief Main function
 * @param argc commandline argument count (ignored)
 * @param argv commandline array of arguments (ignored)
 * @returns 0 on exit
 */
int main(int argc, char const *argv[])
{
	/// string1 and string2 are used to store strings in which we have to find LCS
	char *string1, *string2;                      ///< 2 strings of max size MAX 
	string1 = (char *)calloc(MAX, sizeof(char));  ///< memory allocation for string 1
	string2 = (char *)calloc(MAX, sizeof(char));  ///< memory allocation for string 2

	// To run the test
	if(argc == 2 && strcmp(argv[1], "-test") == 0)
	{
		test();
		return 0;
	}
	// User input case
	printf("Enter string1 : ");
	gets(string1);
	printf("Enter string2 : ");
	gets(string2);
	findAllLCS(string1, string2);
	free(string1);
	free(string2);
	return 0;
}

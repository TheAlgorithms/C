/**
 * @file
 * @author [Santosh Jonnakuti](https://github.com/Santoshjonnakuti)
 * @brief [Longest Common Subsequence Algorithm](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem)
 * implementation in C to find the LCS between 2 strings.
 * @details LCS algorithm uses dynamic approach to find all possible LCS between 2 strings. 
 * Dynamic Programming follow a method so that even sub-problems will also have optimal solution.
 *
 * LCS() will find the length of the LCS of the following two strings 'GAC' and 'AGCAT'.
 * LCS function will return the follwing 2D-Matrix
 *
 *	  0 0 0 0 0 0
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
 *
 * So There are 3 Longest common subsequences in 'GAC' and 'AGCAT'
 */


#include<stdio.h>     /// for I/O operations
#include<stdlib.h>   ///  for Dynamic memory allocation
#include<string.h>  ///   for puts(), gets() and strlen()

#define MAX 100      // maximum size of string1 and string2


// Functions Declaration
int max(int a, int b);
int** LCS(char *string1, int m, char *string2, int n);
void allPossibleLCS(int **c, char *a, int index, int i, int j, char *string1, char *string2);
void print(char *a, int index);

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
void allPossibleLCS(int **c, char *a, int index, int i, int j, char *string1, char *string2)
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
                		allPossibleLCS(c, a, index, i, j-1, string1, string2);
				i--;
			}
			else
			{
				j--;
			}
		}
	}
    for(int i=index-1; i>=0; i--)
	{
		printf("%c", a[i]);
	}
	printf("\n\n");
	return;
}

/**
 * @breif max will find the maximum between 2 values
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
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
	/// string1 and string2 are used to store strings in which we have to find LCS
	char *string1, *string2;                      ///< 2 strings of max size MAX 
	string1 = (char *)calloc(MAX, sizeof(char));  ///< memory allocation for string 1
	string2 = (char *)calloc(MAX, sizeof(char));  ///< memory allocation for string 2
	
	/// Assigning Values of 'GAC' for string1
	string1[0] = 'G';
	string1[1] = 'A';
	string1[2] = 'C';

	/// Assigning Values of 'AGCAT' for string2
	string2[0] = 'A';
	string2[1] = 'G';
	string2[2] = 'C';
	string2[3] = 'A';
	string2[4] = 'T';
	
	// lengths of two Strings;
	int lenOfStr1 = strlen(string1);       /// length of string1
	int lenOfStr2 = strlen(string2);       /// length of string2
	
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
		return 0;
	}
	// If there is a Longest common subsequence then printing them
	printf("All Possible LCS are : \n\n");
	allPossibleLCS(c, a, index, lenOfStr1, lenOfStr2, string1, string2);
	return 0;
}

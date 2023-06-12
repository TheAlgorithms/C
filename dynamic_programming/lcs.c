/**
 * @file
 * @brief [Longest Common
 * Subsequence](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem)
 * algorithm
 * @details
 * From Wikipedia: The longest common subsequence (LCS) problem is the problem
 * of finding the longest subsequence common to all sequences in a set of
 * sequences (often just two sequences).
 * @author [Kurtz](https://github.com/itskurtz)
 */

#include <stdio.h>		/* for io operations */
#include <stdlib.h>		/* for memory management & exit */
#include <string.h>		/* for string manipulation & ooperations */
#include <assert.h>		/* for asserts */

enum {LEFT, UP, DIAG};

/**
 * @brief Computes LCS between s1 and s2 using a dynamic-programming approach
 * @param s1 first null-terminated string
 * @param s2 second null-terminated string
 * @param l1 length of s1
 * @param l2 length of s2
 * @param L matrix of size l1 x l2
 * @param B matrix of size l1 x l2
 * @returns void
 */
void lcslen(const char *s1, const char *s2, int l1, int l2, int **L, int **B) {
	/* B is the directions matrix
	   L is the LCS matrix */
	int i, j;

	/* loop over the simbols in my sequences
	   save the directions according to the LCS */
	for (i = 1; i <= l1; ++i) {
		for (j = 1; j <= l2; ++j) {
			if (s1[i-1] == s2[j-1]) {
				L[i][j] = 1 + L[i-1][j-1];
				B[i][j] = DIAG;
			}
			else if (L[i-1][j] < L[i][j-1]) {
				L[i][j] = L[i][j-1];
				B[i][j] = LEFT;
			}
			else {
				L[i][j] = L[i-1][j];
				B[i][j] = UP;
            }
		}
	}
}

/**
 * @brief Builds the LCS according to B using a traceback approach
 * @param s1 first null-terminated string
 * @param l1 length of s1
 * @param l2 length of s2
 * @param L matrix of size l1 x l2
 * @param B matrix of size l1 x l2
 * @returns lcs longest common subsequence
 */
char *lcsbuild(const char *s1, int l1, int l2, int **L, int **B) {
	int	 i, j, lcsl;
	char	*lcs;
	lcsl = L[l1][l2];
	
	/* my lcs is at least the empty symbol */
	lcs = (char *)calloc(lcsl+1, sizeof(char)); /* null-terminated \0 */
	if (!lcs) {
		perror("calloc: ");
		return NULL;
	}

	i = l1, j = l2;
	while (i > 0 && j > 0) {
		/* walk the matrix backwards */
		if (B[i][j] == DIAG) {
			lcs[--lcsl] = s1[i-1];
			i = i - 1;
			j = j - 1;
		}
        else if (B[i][j] == LEFT)
        {
            j = j - 1;
		}
        else
        {
            i = i - 1;
        }
	}
	return lcs;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
	/* https://en.wikipedia.org/wiki/Subsequence#Applications */
	int **L, **B, j, l1, l2;
	
	char *s1 = "ACGGTGTCGTGCTATGCTGATGCTGACTTATATGCTA";
	char *s2 = "CGTTCGGCTATCGTACGTTCTATTCTATGATTTCTAA";
	char *lcs;
	
	l1 = strlen(s1);
	l2 = strlen(s2);
	
	L = (int **)calloc(l1+1, sizeof(int *));
	B = (int **)calloc(l1+1, sizeof(int *));
	
	if (!L) {
		perror("calloc: ");
		exit(1);
	}
	if (!B) {
		perror("calloc: ");
		exit(1);
	}
	for (j = 0; j <= l1; j++) {
		L[j] = (int *)calloc(l2+1, sizeof(int));
		if (!L[j]) {
			perror("calloc: ");
			exit(1);
		}
		B[j] = (int *)calloc(l2+1, sizeof(int));
		if (!L[j]) {
			perror("calloc: ");
			exit(1);
		}
	}
	
	lcslen(s1, s2, l1, l2, L, B);
	lcs = lcsbuild(s1, l1, l2, L, B);
	
	assert(L[l1][l2] == 27);
	assert(strcmp(lcs, "CGTTCGGCTATGCTTCTACTTATTCTA") == 0);
	
	printf("S1: %s\tS2: %s\n", s1, s2);
	printf("LCS len:%3d\n", L[l1][l2]);
	printf("LCS: %s\n", lcs);

	free(lcs);
    for (j = 0; j <= l1; j++)
    {
        free(L[j]), free(B[j]);
	}
	free(L);
	free(B);

	printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @param argc commandline argument count (ignored)
 * @param argv commandline array of arguments (ignored)
 * @returns 0 on exit
 */
int main(int argc, char *argv[]) {
	test();  // run self-test implementations
	return 0;
}

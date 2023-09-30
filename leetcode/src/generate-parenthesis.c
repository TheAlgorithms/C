// Problem Link: https://leetcode.com/problems/generate-parentheses/ 
// Title: 22. Generate Parentheses

// This C program generates all valid combinations of n pairs of parentheses.
// It uses a recursive approach with backtracking to explore and construct valid combinations.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateParenthesisRecursive(char **result, int *returnSize, char *current, int open, int close, int n) {
    if (strlen(current) == 2 * n) {
        result[(*returnSize)] = strdup(current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[strlen(current)] = '(';
        generateParenthesisRecursive(result, returnSize, current, open + 1, close, n);
        current[strlen(current) - 1] = '\0';  // Backtrack
    }

    if (close < open) {
        current[strlen(current)] = ')';
        generateParenthesisRecursive(result, returnSize, current, open, close + 1, n);
        current[strlen(current) - 1] = '\0';  // Backtrack
    }
}

char **generateParenthesis(int n, int *returnSize) {
    int maxCombinations = 10000;  // Maximum number of combinations
    char **result = (char **)malloc(maxCombinations * sizeof(char *));
    *returnSize = 0;

    char *current = (char *)malloc(2 * n + 1); // Allocate enough memory for the parentheses and null terminator
    memset(current, 0, 2 * n + 1);

    generateParenthesisRecursive(result, returnSize, current, 0, 0, n);
    
    free(current);

    return result;
}


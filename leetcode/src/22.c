#define MAX_COMBINATIONS 1431

int combinationIndex;

// Recursive function to generate valid parentheses combinations
void generateParenthesesUtil(int totalParentheses, int openCount, int closeCount, char **combinations, char *currentCombination, int currentIndex) {
    // Base case: If the total count of open and close parentheses equals n, add the current combination to the result array
    if ((openCount + closeCount) == totalParentheses) {
        combinations[combinationIndex] = currentCombination;
        combinationIndex++;
        return;
    }

    // If the number of open and close parentheses is equal, append a new open parenthesis
    if (openCount == closeCount) {
        currentCombination[currentIndex] = '(';
        generateParenthesesUtil(totalParentheses, openCount + 1, closeCount, combinations, currentCombination, currentIndex + 1);
        return;
    }

    // If there are more open parentheses than close parentheses, try adding a close parenthesis
    if (openCount > closeCount) {
        currentCombination[currentIndex] = ')';
        generateParenthesesUtil(totalParentheses, openCount, closeCount + 1, combinations, currentCombination, currentIndex + 1);

        // If the number of open parentheses is less than half of n, try adding an open parenthesis
        if (openCount < totalParentheses / 2) {
            char *newCombination = (char *)malloc(sizeof(char) * (totalParentheses + 1));
            memcpy(newCombination, currentCombination, currentIndex);
            newCombination[totalParentheses] = '\0';
            newCombination[currentIndex] = '(';
            generateParenthesesUtil(totalParentheses, openCount + 1, closeCount, combinations, newCombination, currentIndex + 1);
        }
    }
}

// Function to generate all valid combinations of parentheses
char **generateParenthesis(int n, int *numCombinations) {
    combinationIndex = 0;
    char **combinations = (char **)malloc(MAX_COMBINATIONS * sizeof(char *));
    char *currentCombination = (char *)malloc(((n * 2) + 1) * sizeof(char));
    currentCombination[n * 2] = '\0';

    // Start the recursive generation process
    generateParenthesesUtil(n * 2, 0, 0, combinations, currentCombination, 0);

    // Set the number of combinations and return the generated array
    *numCombinations = combinationIndex;
    return combinations;
}

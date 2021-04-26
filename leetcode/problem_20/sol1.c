/**
 * \file
 * \brief [20. Valid
 * Parentheses](https://leetcode.com/problems/valid-parentheses/)
 * solution
 * \details
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 * * Open brackets must be closed by the same type of brackets.
 * * Open brackets must be closed in the correct order.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Function to check if input string has valid parantheses.
 *
 * @param s stricng to check
 * @return `true` if valid
 * @return `false` if invalid
 */
bool isValid(const char *s)
{
    int i, k = 0;
    size_t len = strlen(s);
    char *store = calloc(len, sizeof(char));

    for (i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            store[k++] = s[i];
            break;
        case ')':
            if (k < 1 || store[--k] != '(')
                goto out;
            break;
        case '}':
            if (k < 1 || store[--k] != '{')
                goto out;
            break;
        case ']':
            if (k < 1 || store[--k] != '[')
                goto out;
            break;
        }
    }
out:
    free(store);
    return s[i] == '\0' && k == 0;
}

/**
 * @brief Main function
 * @return 0
 */
int main()
{
    assert(isValid("()") == true);
    printf("Test 1 passed\n");
    assert(isValid("()[]{}") == true);
    printf("Test 2 passed\n");
    assert(isValid("(]") == false);
    printf("Test 3 passed\n");
    assert(isValid("([)]") == false);
    printf("Test 4 passed\n");
    assert(isValid("{[]}") == true);
    printf("Test 5 passed\n");

    return 0;
}

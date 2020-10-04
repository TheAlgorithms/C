/**
 * @file america_flag_sort.c
 * @brief [American Flag sort](https://en.wikipedia.org/wiki/American_flag_sort)
 * @details
 * An American flag sort is an efficient, in-place variant of BUCKET sort that
 * distributes items into buckets. Non-comparative sorting algorithms such as
 * BUCKET sort and American flag sort are typically used to sort large objects
 * such as strings, for which comparison is not a unit-time operation.
 *
 * This implementation is based on the Java implementation done by Robert
 * Sedgewick and Kevin Wayne for the book Algorithms, 4th Edition. The
 * implementation can be found at
 * https://github.com/kevin-wayne/algs4/blob/master/src/main/java/edu/princeton/cs/algs4/AmericanFlag.java
 * which has the GNU General Public License.
 *
 * Thus the implementation is different compared to the pseudocode on the
 * Wikipedia page, however the core concepts remain the same.
 *
 * This implemention also uses a simple stack which is obtained from
 * https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
 * If needed the implementation of the stack could be replaced.
 *
 * @author [Jian](https://github.com/JianLoong)
 *
 **/

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define R 256

#define STACK_SIZE 10

#define LENGTH_OF_STRING 9
#define NUMBER_OF_STRING 14

/**
 * @brief Stack struct
 * Taken from
 * https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
 */
struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack) { return stack->top == stack->capacity - 1; }

int isEmpty(struct Stack *stack) { return stack->top == -1; }

void push(struct Stack *stack, int item)
{
    if (isFull(stack))
    {
        return;
    }

    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

/**
 * Returns the dth character of s.
 *
 * @param s[] The char array
 * @param d the dth character
 * @return the dth character of s, -1 if d = length of the string
 */
int charAt(char s[], int d)
{
    assert(d >= 0 && d <= strlen(s));
    if (d == strlen(s))
    {
        return -1;
    }
    return s[d];
}

/**
 * Exchange two strings within an array of strings.
 *
 * @param i the position to be exchanged
 * @param j the position to be exchanged
 */
void exch(char *a[], int i, int j)
{
    char *temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

/**
 * The main American Flag sort.
 *
 * @param char_array A pointer to an array of strings.
 * @param lo the starting position
 * @param hi the hi of the string. (The end index of the array initially)
 */
void sort(char *a[LENGTH_OF_STRING], int lo, int hi)
{
    struct Stack *stack = createStack(STACK_SIZE);
    int first[R + 2] = {0};
    int next[R + 2] = {0};
    int d = 0;

    push(stack, lo);
    push(stack, hi);
    push(stack, d);

    while (!isEmpty(stack))
    {
        d = pop(stack);
        hi = pop(stack);
        lo = pop(stack);

        // compute frequency counts
        for (int i = lo; i <= hi; i++)
        {
            int c = charAt(a[i], d) +
                    1;  // account for -1 representing end-of-string
            first[c + 1]++;
        }

        first[0] = lo;
        for (int c = 0; c <= R; c++)
        {
            first[c + 1] += first[c];

            if (c > 0 && first[c + 1] - 1 > first[c])
            {
                // add subproblem for character c (excludes sentinel c == 0)
                push(stack, first[c]);
                push(stack, first[c + 1] - 1);
                push(stack, d + 1);
            }
        }

        for (int c = 0; c < R + 2; c++) next[c] = first[c];

        // permute data in place
        for (int k = lo; k <= hi; k++)
        {
            int c = charAt(a[k], d) + 1;
            while (first[c] > k)
            {
                exch(a, k, next[c]++);
                c = charAt(a[k], d) + 1;
            }
            next[c]++;
        }

        // clear first[] and next[] arrays
        for (int c = 0; c < R + 2; c++)
        {
            first[c] = 0;
            next[c] = 0;
        }
    }
}

/**
 * The test case here is based on the sample used for the tongue twister
 * "She sells seashells by the seashoe the shells she sells are surely shells"
 */
static void test()
{
    char *ch_arr[NUMBER_OF_STRING] = {
        "she", "sells",  "seashells", "by",    "the", "sea",    "shore",
        "the", "shells", "she",       "sells", "are", "surely", "seashells"};

    printf("Before sorting\n");
    for (int i = 0; i < NUMBER_OF_STRING; i++)
    {
        printf("%s, ", ch_arr[i]);
    }

    sort(ch_arr, 0, NUMBER_OF_STRING - 1);

    printf("\nAfter sorting\n");
    for (int i = 0; i < NUMBER_OF_STRING; i++)
    {
        printf("%s, ", ch_arr[i]);
    }
}

// Test harness
int main()
{
    test();
    return 0;
}

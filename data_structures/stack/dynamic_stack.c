/**
 * @file
 *
 * @brief
 * Dynamic [Stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)),
 * just like Dynamic Array, is a stack data structure whose the length or
 * capacity (maximum number of elements that can be stored) increases or
 * decreases in real time based on the operations (like insertion or deletion)
 * performed on it.
 *
 * In this implementation, functions such as PUSH, POP, PEEK, show_capacity,
 * isempty, and stack_size are coded to implement dynamic stack.
 *
 * @author [SahilK-027](https://github.com/SahilK-027)
 *
 */
#include <assert.h>  /// to verify assumptions made by the program and print a diagnostic message if this assumption is false.
#include <inttypes.h>  /// to provide a set of integer types with universally consistent definitions that are operating system-independent
#include <stdio.h>     /// for IO operations
#include <stdlib.h>  /// for including functions involving memory allocation such as `malloc`
/**
 * @brief DArrayStack Structure of stack.
 */
typedef struct DArrayStack
{
    int capacity, top;  ///< to store capacity and top of the stack
    int *arrPtr;        ///< array pointer
} DArrayStack;

/**
 * @brief Create a Stack object
 *
 * @param cap Capacity of stack
 * @return DArrayStack* Newly created stack object pointer
 */
DArrayStack *create_stack(int cap)
{
    DArrayStack *ptr;
    ptr = (DArrayStack *)malloc(sizeof(DArrayStack));
    ptr->capacity = cap;
    ptr->top = -1;
    ptr->arrPtr = (int *)malloc(sizeof(int) * cap);
    printf("\nStack of capacity %d is successfully created.\n", ptr->capacity);
    return (ptr);
}

/**
 * @brief As this is stack implementation using dynamic array this function will
 * expand the size of the stack by twice as soon as the stack is full.
 *
 * @param ptr Stack pointer
 * @param cap Capacity of stack
 * @return DArrayStack*: Modified stack
 */
DArrayStack *double_array(DArrayStack *ptr, int cap)
{
    int newCap = 2 * cap;
    int *temp;
    temp = (int *)malloc(sizeof(int) * newCap);
    for (int i = 0; i < (ptr->top) + 1; i++)
    {
        temp[i] = ptr->arrPtr[i];
    }
    free(ptr->arrPtr);
    ptr->arrPtr = temp;
    ptr->capacity = newCap;
    return ptr;
}

/**
 * @brief As this is stack implementation using dynamic array this function will
 * shrink the size of stack by twice as soon as the stack's capacity and size
 * has significant difference.
 *
 * @param ptr Stack pointer
 * @param cap Capacity of stack
 * @return DArrayStack*: Modified stack
 */
DArrayStack *shrink_array(DArrayStack *ptr, int cap)
{
    int newCap = cap / 2;
    int *temp;
    temp = (int *)malloc(sizeof(int) * newCap);
    for (int i = 0; i < (ptr->top) + 1; i++)
    {
        temp[i] = ptr->arrPtr[i];
    }
    free(ptr->arrPtr);
    ptr->arrPtr = temp;
    ptr->capacity = newCap;
    return ptr;
}

/**
 * @brief The push function pushes the element onto the stack.
 *
 * @param ptr Stack pointer
 * @param data Value to be pushed onto stack
 * @return int Position of top pointer
 */
int push(DArrayStack *ptr, int data)
{
    if (ptr->top == (ptr->capacity) - 1)
    {
        ptr = double_array(ptr, ptr->capacity);
        ptr->top++;
        ptr->arrPtr[ptr->top] = data;
    }
    else
    {
        ptr->top++;
        ptr->arrPtr[ptr->top] = data;
    }
    printf("Successfully pushed : %d\n", data);
    return ptr->top;
}

/**
 * @brief The pop function to pop an element from the stack.
 *
 * @param ptr Stack pointer
 * @return int Popped value
 */
int pop(DArrayStack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is empty UNDERFLOW \n");
        return -1;
    }
    int ele = ptr->arrPtr[ptr->top];
    ptr->arrPtr[ptr->top] = 0;
    ptr->top = (ptr->top - 1);
    if ((ptr->capacity) % 2 == 0)
    {
        if (ptr->top <= (ptr->capacity / 2) - 1)
        {
            ptr = shrink_array(ptr, ptr->capacity);
        }
    }
    printf("Successfully popped: %d\n", ele);
    return ele;
}

/**
 * @brief To retrieve or fetch the first element of the Stack or the element
 * present at the top of the Stack.
 *
 * @param ptr Stack pointer
 * @return int Top of the stack
 */
int peek(DArrayStack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is empty UNDERFLOW \n");
        return -1;
    }
    return ptr->arrPtr[ptr->top];
}

/**
 * @brief To display the current capacity of the stack.
 *
 * @param ptr Stack pointer
 * @return int Current capacity of the stack
 */
int show_capacity(DArrayStack *ptr) { return ptr->capacity; }

/**
 * @brief The function is used to check whether the stack is empty or not and
 * return true or false accordingly.
 *
 * @param ptr Stack pointer
 * @return int returns 1 -> true OR returns 0 -> false
 */
int isempty(DArrayStack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Used to get the size of the Stack or the number of elements present in
 * the Stack.
 *
 * @param ptr Stack pointer
 * @return int size of stack
 */
int stack_size(DArrayStack *ptr) { return ptr->top + 1; }

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test()
{
    DArrayStack *NewStack;
    int capacity = 1;
    NewStack = create_stack(capacity);
    uint64_t arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    printf("\nTesting Empty stack: ");
    assert(stack_size(NewStack) == 0);
    assert(isempty(NewStack) == 1);
    printf("Size of an empty stack is %d\n", stack_size(NewStack));

    printf("\nTesting PUSH operation:\n");
    for (int i = 0; i < 12; ++i)
    {
        int topVal = push(NewStack, arr[i]);
        printf("Size: %d, Capacity: %d\n\n", stack_size(NewStack),
               show_capacity(NewStack));
        assert(topVal == i);
        assert(peek(NewStack) == arr[i]);
        assert(stack_size(NewStack) == i + 1);
        assert(isempty(NewStack) == 0);
    }

    printf("\nTesting POP operation:\n");
    for (int i = 11; i > -1; --i)
    {
        peek(NewStack);
        assert(peek(NewStack) == arr[i]);
        int ele = pop(NewStack);
        assert(ele == arr[i]);
        assert(stack_size(NewStack) == i);
    }

    printf("\nTesting Empty stack size: ");
    assert(stack_size(NewStack) == 0);
    assert(isempty(NewStack) == 1);
    printf("Size of an empty stack is %d\n", stack_size(NewStack));

    printf("\nTesting POP operation on empty stack: ");
    assert(pop(NewStack) == -1);
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main()
{
    test();  // run self-test implementations
    return 0;
}

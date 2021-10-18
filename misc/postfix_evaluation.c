/**
 * @file
 * @brief [Postfix evaluation algorithm](https://www.includehelp.com/c/evaluation-of-postfix-expressions-using-stack-with-c-program.aspx) implementation
 * @details
 * The input postfix expression is of type string upto 24 characters (single digit numbers only).
 * Supported operations- '+', '-', '/', '*', '%'
 * @author [Kumar Yash](https://github.com/kumaryash18)
 */
 
#include <stdio.h>	/// for IO operations
#include <string.h>	/// for strlen()
#include <ctype.h>	/// for isdigit()
#include <stdlib.h>	/// for exit()
#include <stdint.h>	/// for int8_t
#include <assert.h>	/// for assert

/**
 * @brief array implementation of stack using structure
 */
struct Stack {
	int stack[20];		///< array stack
	int top;		///< stores index of the top element
};
struct Stack st;		///< global declaration of stack st

/**
 * @brief Function to push on the stack
 * @param opd number to be pushed in the stack
 * @returns void
 */
void push(int8_t opd) {
	if(st.top == 19)	{		// overflow condition
		printf("Stack overflow...");
		exit(1);
	}
	st.top++;
	st.stack[st.top] = opd;
}

/**
 * @brief Function to pop from the stack
 * @returns popped number
 */
int8_t pop() {
	int8_t item;				///< to store the popped value to be returned
	if(st.top == -1) {		// underflow condition
		printf("Stack underflow...");
		exit(1);
	}
	item = st.stack[st.top];
	st.top--;
	return item;
}

/**
 * @brief Function to evaluate postfix expression
 * @param post the input postfix expression
 * @returns evaluated answer
 */
int8_t evaluate(char post[]) {
	int8_t it1;
	int8_t it2;
	int8_t temp;
    int i;
    for(i = 0; i < strlen(post); i++) {
		if(isdigit(post[i])) {
			push(post[i]-'0');
		}
		else {
			it2 = pop();
			it1 = pop();
			switch(post[i]) {
				case '+':
				temp = it1 + it2; break;
				case '-':
				temp = it1 - it2; break;
				case '*':
				temp = it1 * it2; break;
				case '/':
				temp = it1 / it2; break;
				case '%':
				temp = it1 % it2; break;
				default:
				printf("Invalid operator"); exit(1);
			}
			push(temp);
		}
	}
	return pop();
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    /* check sample test case
	   input: "4572+-*"
	   expected output: -16
	 */
	assert(evaluate("4572+-*") == -16); 			/// this ensures that the algorithm works as expected
	/* input: "42+351-*+"
	   expected output: 18
	 */
	assert(evaluate("42+351-*+") == 18); 			/// this ensures that the algorithm works as expected
	printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	st.top = -1;			/// initialize
	test();				/// run self-test implementations
	char post[25];			///< to store input postfix expression
	printf("Enter postfix: ");
	scanf("%s", post);
	printf("Evaluated answer: %d", evaluate(post));
	return 0;
}

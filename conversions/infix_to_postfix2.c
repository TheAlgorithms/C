/**
 * @file
 * @brief [Infix to Postfix converter](https://www.includehelp.com/c/infix-to-postfix-conversion-using-stack-with-c-program.aspx) implementation
 * @details
 * The input infix expression is of type string upto 24 characters.
 * Supported operations- '+', '-', '/', '*', '%'
 * @author [Kumar Yash](https://github.com/kumaryash18)
 * @see infix_to_postfix.c
 */
 
#include <stdio.h>	/// for IO operations
#include <string.h>	/// for strlen(), strcmp()
#include <ctype.h>	/// for isalnum()
#include <stdlib.h>	/// for exit()
#include <stdint.h>	/// for uint16_t, int16_t
#include <assert.h>	/// for assert

/**
 * @brief array implementation of stack using structure
 */
struct Stack {
	char stack[10];		///< array stack
	int top;		///< stores index of the top element
};
struct Stack st;		///< global declaration of stack st

/**
 * @brief Function to push on the stack
 * @param opd character to be pushed in the stack
 * @returns void
 */
void push(char opd) {
	if(st.top == 9)	{		// overflow condition
		printf("Stack overflow...");
		exit(1);
	}
	st.top++;
	st.stack[st.top] = opd;
}

/**
 * @brief Function to pop from the stack
 * @returns popped character
 */
char pop() {
	char item;				///< to store the popped value to be returned
	if(st.top == -1) {		// underflow condition
		printf("Stack underflow...");
		exit(1);
	}
	item = st.stack[st.top];
	st.top--;
	return item;
}

/**
 * @brief Function to check whether the stack is empty or not
 * @returns 1 if the stack IS empty
 * @returns 0 if the stack is NOT empty
 */
uint16_t isEmpty() {
	if(st.top == -1) {
		return 1;
	}
	return 0;
}

/**
 * @brief Function to get top of the stack
 * @returns top of stack
 */
char Top() {
	return st.stack[st.top];
}

/**
 * @brief Function to check priority of operators
 * @param opr operator whose priority is to be checked
 * @returns 0 if operator is '+' or '-'
 * @returns 1 if operator is '/' or '*' or '%'
 * @returns -1 otherwise
 */
int16_t priority(char opr) {
	if(opr == '+' || opr == '-') {
		return 0;
	}
	else if(opr == '/' || opr == '*' || opr == '%') {
		return 1;
	}
	else {
		return -1;
	}
}

/**
 * @brief Function to convert infix expression to postfix expression
 * @param inf the input infix expression
 * @returns output postfix expression
 */
char *convert(char inf[]) {
	static char post[25];				///< to store the postfix expression
	int i;								///< loop iterator
	int j = 0;							///< keeps track of end of postfix string
	for(i = 0; i < strlen(inf); i++) {
		if(isalnum(inf[i]))	{			// if scanned element is an alphabet or number
			post[j] = inf[i];			// append in postfix expression
			j++;
		}
		else if(inf[i] == '(') {		// if scanned element is opening parentheses
			push(inf[i]);				// push on stack.
		}
		else if(inf[i] == ')') {		// if scanned element is closing parentheses,
			while(Top() != '(') {		// pop elements from stack and append in postfix expression
				post[j] = pop();		// until opening parentheses becomes top.
				j++;
			}
			pop();						// pop opening parentheses
		}
		else {							// if scanned element is an operator
			while( (!isEmpty()) && (priority(inf[i]) <= priority(Top())) ) {	// pop and append until stack becomes
				post[j] = pop();												// empty or priority of top operator
				j++;															// becomes smaller than scanned operator
			}																	// '(' has priority -1
			push(inf[i]);				// push the scanned operator
		}
	}
	while(!isEmpty()) {					// pop and append residual operators from stack
		post[j] = pop();
		j++;
	}
	post[j] = '\0';						// end postfix string with null character
	return post;
}

/**
 * @brief Self-test implementations
 * @returns void
 */
static void test() {
    /* check sample test case
	   input- "(A/(B-C)*D+E)"
	   expected output- "ABC-/D*E+"
	 */
	assert(strcmp(convert("(A/(B-C)*D+E)"), "ABC-/D*E+") == 0); 			/// this ensures that the algorithm works as expected
	/* input- "7-(2*3+5)*(8-4/2)"
	   expected output- "723*5+842/-*-"
	 */
	assert(strcmp(convert("7-(2*3+5)*(8-4/2)"), "723*5+842/-*-") == 0); 			/// this ensures that the algorithm works as expected
	printf("All tests have successfully passed!\n");
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	st.top = -1;			/// initialize
	test();				/// run self-test implementations
	char inf[25];			///< to store input infix expression
	printf("Enter infix: ");
	scanf("%s", inf);
	printf("Postfix: %s", convert(inf));
	return 0;
}

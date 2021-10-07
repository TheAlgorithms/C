/**
 * @file
 * @brief infix to postfix converter
 * @details
 * The input infix expression is of type string upto 24 characters.
 * 
 * Supported operations- '+', '-', '/', '*', '%'
 *
 * @author [Kumar Yash](https://github.com/kumaryash18)
 * @see infix_to_postfix.c
 */
 
#include<stdio.h>	/// for IO operations
#include<string.h>	/// for strlen()
#include<ctype.h>	/// for isalnum()
#include<process.h>	/// for exit()

/**
 * @brief array implementation of stack using structure
 */
struct Stack {
	char stack[10];	//< array stack
	int top;		//< stores index of top element
};
struct Stack st;	// global declaration of stack st

/**
 * @brief Function to push '(' and operators from infix expression
 * @param opd- character to be pushed in stack
 * @returns void
 */
void push(char opd) {
	if(st.top == 9)		// overflow condition
	{
		printf("Stack overflow...");
		exit(0);
	}
	st.top++;
	st.stack[st.top] = opd;
}

/**
 * @brief Function to pop operators and '('
 * @returns popped character
 */
char pop() {
	char item;
	if(st.top == -1)	// underflow condition
	{
		printf("Stack underflow...");
		exit(0);
	}
	item = st.stack[st.top];
	st.top--;
	return item;
}

/**
 * @brief Function to check whether stack is empty or not
 * @returns `true` if stack is empty
 * @returns `false` if stack is not empty
 */
int isEmpty() {
	if(st.top == -1)
		return 1;
	return 0;
}

/**
 * @brief Function to get top of stack
 * @returns top of stack
 */
char Top() {
	return st.stack[st.top];
}

/**
 * @brief Function to check priority of operators
 * @param opd- operator whose priority is to be checked
 * @returns 0 if operator is '+' or '-'
 * @returns 1 if operator is '/' or '*' or '%'
 * @returns -1 otherwise
 */
int priority(char opd) {
	if(opd == '+' || opd == '-')
		return 0;
	else if(opd == '/' || opd == '*' || opd == '%')
		return 1;
	else
		return -1;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	st.top = -1;				// represents empty stack
	char inf[25], post[25];
	printf("Enter Infix: ");
	scanf("%s", inf);			// input infix expression
	int i, j=0;
	for(i=0; i < strlen(inf); i++)
	{
		if(isalnum(inf[i]))		// if scanned element is an alphabet or number
		{
			post[j] = inf[i];	// append in postfix expression
			j++;
		}
		else if(inf[i] == '(')	// if scanned element is opening parentheses
			push(inf[i]);		// push on stack.
		else if(inf[i] == ')')	// if scanned element is closing parentheses,
		{
			while(Top() != '(')	// pop elements from stack and append in postfix expression
			{					// until opening parentheses becomes top
				post[j] = pop();
				j++;
			}
			pop();				// pop opening parentheses
		}
		else					// if scanned element is an operator
		{
			while( (!isEmpty()) && (priority(inf[i]) <= priority(Top())) )	// pop and append until stack becomes
			{																// empty or priority of top operator
				post[j] = pop();											// becomes smaller than scanned operator
				j++;														// '(' has priority -1
			}
			push(inf[i]);		// push the scanned operator
		}
	}
	while(!isEmpty())			// pop and append residual operators from stack
	{
		post[j] = pop();
		j++;
	}
	post[j] = '\0';
	printf("Postfix: %s", post);	// print postfix expression
	return 0;
}


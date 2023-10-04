/**
 * @file
 * @brief [Infix to Prefix converter]
 * @details
 * The input infix expression is of type string upto 24 characters.
 * Supported operations- '+', '-', '/', '*', '%','^'
 * @author [Jibesh Roy](https://github.com/Jibesh10101011)
 * @see infix_to_prefix.c
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>
#define sz 1000      // Maximum size of infix string
#define ln 2000     //  Maximum size of the resultant prefix string 
/**
 * @brief dynnamic implementation of stack using structure
*/
typedef struct  node
{
    char data;
    struct node *next;
}node;
typedef struct stack {
    node *head;
}stack;
stack* createStack()  // Create a stack dynamically 
{
    stack *s=(stack*)malloc(sizeof(stack));
    s->head=NULL;
    return s;
}

/**
 * @brief Function to push on the stack
 * @param opd character to be pushed in the stack
 * @returns void
 */
void push(stack *s,char x)
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=x;
    ptr->next=s->head;
    s->head=ptr;
}
/**
 * @brief Function to pop from the stack
 * @returns popped character
 */
char pop(stack *s)
{
    char ch='\0';
    if(s->head)       // Checking the underflow condition 
    {   
        node *temp=s->head;
        ch=temp->data;
        s->head=s->head->next;
        free(temp);            // Deleting extra space 
    }
    return ch;
}
/**
 * @brief Function to top from the stack
 * @returns the top element of the stack
 */
char top(stack *s)
{
    if(s->head)              //cheking the underflow condition 
    return s->head->data;
    return '\0';
}
/**
 * @brief Function to get priority of operator 
 * @returns priority of a symbol('+', '-', '/', '*', '%','^')
 */
int priority(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        case '%':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}

/**
 * @brief Function to convert infix expression to postfix
 * @returns the final postfix expression 
 */
char* infixToPostfix(char *s)
{
    int n=strlen(s),ptop;
    char *fnl=(char*)malloc(sizeof(char)*ln),ch;
    stack *stk=createStack();                       
    int idx=0;
    push(stk,'(');                         // If user doesn't input '(' at begining then push '(' in stack
    s[n]=')',s[n+1]='\0',n++;              // If user doesn't input ')' at the end then add ')' end of the string 
    for(int i=0;i<n;i++)
    { 
        switch(s[i])                     
        {
            case '(':                      // if s[i]=='(' then push on stack
                push(stk,'(');
                break;
            case ')':                      // if s[i]==') then pop from the stack
                ch=pop(stk);              
                while(ch!='(')             // while ch!='('   
                {
                    fnl[idx++]=ch;         // inserting ch to fnl string 
                    ch=pop(stk);           // pop from the stack
                }
                break;
            case '^':                     // As '^' priority R-->L 
                push(stk,'^');            // if s[i]=='^' push on stack 
                break;
            case '+':                     
            case '-':
            case '*':
            case '/':
            case '%':
                ch=top(stk);
                ptop=priority(s[i]); 
                while(ptop<priority(ch))    //While priority of ptop < priority of the top character of the stack
                {                                                 
                    fnl[idx++]=ch;          // Insert at last of the final string
                    pop(stk);               // pop from the stack
                    ch=top(stk);            // For checking the next top element's priority top() from the stack
                }
                push(stk,s[i]);             // Push s[i] to the stack
                break;
            default :
                fnl[idx++]=s[i];            // If s[i] neither operator nor parenthesis then simply add s[i] to the final string
        }
    }
    fnl[idx]='\0';              // At the end we need to insert a null character for a valid string
    return fnl;
}

/**
 * @brief Function to reverse a string 
 * @returns void
 */
void reverse(char *s)   
{
    int n=strlen(s);
    for(int i=0;i<n/2;i++)
        s[i]=s[n-i-1]+s[i]-(s[n-i-1]=s[i]); // Swapping
}

/**
 * @brief Function to convert infix expression to prefix 
 * @returns resultant prefix_expression
 */
char* infix_to_prefix(char *s)
{
    int n=strlen(s);
    if(n%2)                    // Reversing the string using n/2 operations if n odd then n/2 character
    {                         //  Will be unchecked 
        if(s[n/2]=='(')
            s[n/2]=')';
        else if(s[n/2]==')')
            s[n/2]='(';
    }
    for(int i=0;i<n/2;i++)        //Reversing the string 
    {
        if(s[i]==')')
            s[i]='(';
        else if(s[i]=='(')
            s[i]=')';

        if(s[n-i-1]=='(')
            s[n-i-1]=')';
        else if(s[n-i-1]==')')
            s[n-i-1]='(';

        s[i]=s[n-i-1]+s[i]-(s[n-i-1]=s[i]); //Swapping of two characters
    }
    char *fnl=infixToPostfix(s);
    reverse(fnl);
    return fnl;
}
/**
 * @brief Self-test implementations
 * @returns void
 */
void test() {
    // check sample test case
	// input- "(A+B/C)*(D+E/F*G)"
    // expected output - "*+A/BC+D*/EFG"
    char s1[sz]="(A+B/C)*(D+E/F*G)";
    char *u=infix_to_prefix(s1);
	assert(strcmp(u,"*+A/BC+D*/EFG") == 0); 			/// this ensures that the algorithm works as expected
	/* input- "(A+B*C/(E+F/G))"
	   expected output- "+A/*BC+E/FG"
	 */
    char s2[sz]="(A+B*C/(E+F/G))";
    u=infix_to_prefix(s2);
	assert(strcmp(u,"+A/*BC+E/FG") == 0); 			/// this ensures that the algorithm works as expected
    /* input- "(A+B^C^D/F(G+H*I))"
	   expected output- "+A/^^BCDF+G*HI"
	*/
    char s3[sz]="(A+B^C^D/F(G+H*I))";
    u=infix_to_prefix(s3);
    assert(strcmp(u,"+A/^^BCDF+G*HI")==0);

     /* input- "A-(B*C+D)*(E-F/G)"
	   expected output- "-A*+*BCD-E/FG"
	 */
    char s4[sz]="A-(B*C+D)*(E-F/G)";
    u=infix_to_prefix(s4);
    assert(strcmp(u,"-A*+*BCD-E/FG")==0);
	printf("All tests have successfully passed!\n");
}
int main()
{
    test();
    return 0;
}
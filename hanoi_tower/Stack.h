typedef struct stack Stack;

Stack *create();
void destroy(Stack *p);
void stackUp(Stack *p, int x); // push
int unstack(Stack *p);         // pop

int length(Stack *p);
int top(Stack *p);
void printStack(Stack *p);

void reverse3(Stack *p);
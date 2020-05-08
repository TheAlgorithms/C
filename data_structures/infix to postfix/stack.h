#define N 50
typedef struct {
    int data[N];
    int top;
}STACK;

void init(STACK *s){
    s->top = -1;
    //printf("Stack initialized...\n");
}

void push(STACK *s,int val){
    if(s->top==N-1){
        //printf("Stack Overflow...\n");
    }
    else{
        s->top++;
        s->data[s->top]=val;
        //printf("Value %d inserted...\n",val);
    }
}

int pop(STACK *s){
    int val=NULL;
    if(s->top==-1){
        //printf("Stack Underflow...\n");
    }
    else{
        val=s->data[s->top];
        s->top--;
    }
    return val;
}

int peep(STACK *s){
    int val=NULL;
    if(s->top==-1){
        //printf("Stack Underflow...\n");
    }
    else{
        val=s->data[s->top];
    }
    return val;
}

void change(STACK *s,int pos,int val){
    int i = s->top-pos+1; // calculating index from position
    if(i>=0 && i<=s->top){
        s->data[i]=val;
        printf("Value changed...\n");
    }
    else{
        printf("Invalid position...\n");
    }
}

void search(STACK *s,int val){
    int i,flag=0;

    for(i=s->top;i>=0;i--){
        if(s->data[i]==val){
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("value found...\n");
    else
        printf("value not found...\n");
}

void display(STACK *s){
    int i;
    if(s->top==-1){
        printf("Stack is empty...\n");
    }
    else{
        printf("Stack contains:\n");
        for(i=s->top;i>=0;i--){
            printf("%d\n",s->data[i]);
        }
    }
}
void display2(STACK *s){
    int i;
    if(s->top==-1){
        //printf("Stack is empty...\n");
    }
    else{
        //printf("Stack contains:\n");
        for(i=s->top;i>=0;i--){
            printf("%c",s->data[i]);
        }
    }
}

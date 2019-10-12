typedef struct link{
    int element;
    struct link *next;
} Link;

typedef struct{
    Link *top;
    int size;
} Stack;

Link *create_link(int it, Link *nextval){
    Link *n;
    n = (Link*) malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Stack *create_stack(){
    Stack *s;
    s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack *s, int it){
    s->top = create_link(it, s->top);
    s->size++;
}

int pop(Stack *s){
    int it;
    Link *n;
    if(s->top == NULL){
        return -1;
    }
    it = s->top->element;
    n = s->top;
    s->top = s->top->next ;
    free(n);
    s->size--;
    return it;
}

void clear(Stack *s){
    while(s->top != NULL){
        pop(s);
    }
    free(s);
}

int topValue(Stack *s){
    if(s->top == NULL){
        return -1;
    }
    return s->top->element;
}

int lenght(Stack *s){
    return s->size;
}

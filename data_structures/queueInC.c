#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct link{
    int element;
    struct link *next;
} Link;

typedef struct{
    Link *front;
    Link *rear;
    int size;
} Queue;

Link *create_Link(int it, Link *nextval){
    Link *n;
    n = (Link*) malloc(1*sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

Link *create_link(Link *nextval){
    Link *n;
    n = (Link*) malloc(1*sizeof(Link));
    n->next = nextval;
    return n;
}

Queue *create_queue(){
    Queue *q;
    q = (Queue*) malloc(1*sizeof(Queue));
    (*q).rear = create_link(NULL);
    q->front = q->rear;
    q->size = 0;
    return q;
}

void clear(Queue *q){
    q->rear = q->front;
    Link *tmp;
    while(q->rear != NULL) {
        tmp = q->rear;
        q->rear = q->rear->next;
        free(tmp);
    }
    q->size = 0;
    free(q);
}

void enqueue(Queue *q, int it){
    q->rear->next = create_Link(it, NULL);
    q->rear = q->rear->next;
    q->size++;
}

int dequeue(Queue *q){
    Link *temp;
    if(q->size == 0){
        return -1;
    }
    int it = q->front->next->element;
    temp = q->front->next;
    q->front->next = q->front->next->next;
    if(q->front->next == NULL){
        q->rear = q->front;
    }
    free(temp);
    q->size--;
    return it;
}

int frontValue(Queue *q){
    if(q->size == 0){
        return -1;
    }
    return q->front->next->element;
}

int lenght(Queue *q){
    return q->size;
}

#define max 1000

int main(){
    
    Queue *left, *right;
    int i, c, cont = 0, flag = 1, viagem = 0;
    int l, m, it;
    int actual, total = 0, total2 = 0;
    char side[max];

    scanf("%d", &c);
    //printf("Casos Teste %d\n", c);

    while(cont < c){
        left = create_queue();
        right = create_queue();
        scanf("%d %d", &l, &m);
        for(i = 0; i < m; i++){
            scanf("%d %[^\n]", &it, side);
            //printf("%d %s\n", it, side);
            if(strcasecmp(side, "left") == 0){
                enqueue(left, it);
            }else{
                enqueue(right, it);
            }
        }
        l = l*100;
        flag = 1;
        while((lenght(left) != 0) || (lenght(right) != 0)){
            total = 0;
            if(flag == 1){
                while(frontValue(left) != -1 && total+frontValue(left) <= l){
                    actual = dequeue(left);
                    //printf("1 - %d\n", actual);
                    total += actual;
                }
            }else{
                while(frontValue(right) != -1 && total+frontValue(right) <= l){
                    actual = dequeue(right);
                    //printf("0 - %d\n", actual);
                    total += actual;
                }
            }
            flag = (flag+1)%2;
            viagem++;
        }
        printf("%d\n", viagem);
        viagem = 0;
        clear(right);
        clear(left);
        cont++;
    }
    
    return 0;
}

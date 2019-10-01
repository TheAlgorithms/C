#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Nessa struct nós criamos o nó (Link), onde temos um elemento 
e um ponteiro que vai apontar para o próximo elemento.
*/

typedef struct link{
    int element;
    struct link *next;
} Link;

/*
Agora criamos a struct da stack, temos um nó (Link) que aponta
para o topo da nossa stack e um inteiro chamado size que me diz
o tamanho da minha stack.
*/

typedef struct{
    Link *top;
    int size;
} Stack;

/*
Aqui nós criamos um novo Link, primeiro nós damos um malloc
no Link n de sizeof(Link), após isso colocamos o valor it, que é o
novo valor que vamos inserir no element do nosso Link n, e colocamos para
o nosso ponteiro next apontar para o nextval passado para função, por fim
nós retornamos o n, que vai ser um novo link criado.
*/

Link *create_link(int it, Link *nextval){
    Link *n;
    n = (Link*) malloc(sizeof(Link));
    n->element = it;
    n->next = nextval;
    return n;
}

/*
Na função create_stack nós criamos uma stack, primeiro criamos
um ponteiro do tipo stack, depois utilizamos um malloc sizeof(Stack)
para poder utilizar o ponteiro, depois eu seto o ponteiro que aponta 
para o topo da stack como NULL e seto o tamanho da stack para 0, 
então asiim nós criamos uma nova stack "sem nada".
*/

Stack *create_stack(){
    Stack *s;
    s = (Stack*) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

/*
Primeiro recebemos a nossa stack como parâmetro e o novo valor a ser inserido, agora nós
atualizamos o topo da nossa stack, associando a ele um novo link que vai ser criado
ao chamarmos a função create_link, passamos o valor a ser inserido e o topo atual da nossa stack
para a função create link, dessa forma ele cria um novo link que vai ser o nosso topo atual e vai
apontar para o "topo antigo", e por fim incrementamos o tamanho da nossa stack.
*/

void push(Stack *s, int it){
    s->top = create_link(it, s->top);
    s->size++;
}

/*
Nessa função de pop, nós removemos o elemento do topo da nossa stack,
primeiros salvamos o elemento que está no topo da nossa stack num inteiro
chamado it, e logo após isso atualizamos o nosso topo, dizemos que o nosso novo
topo da stack é o que está "abaixo do topo antigo" (ex:. topo atual = 5, abaixo do topo = 6
agora nós dizemos que o topo atual = 6) e por fim nós decrementamos o tamanho da nossa stack
e retornamos o elemento da nossa stack que está salva na variável it.
*/

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

/* 
Aqui nós implementamos a função clear para limpar a nossa stack, dando free
em todas as posições da mesma chamando a nossa função pop enquanto o topo da nossa
stack for diferente de NULL, porque isso quer dizer que ainda temos elementos presentes
na nossa stack.
*/

void clear(Stack *s){
    while(s->top != NULL){
        pop(s);
    }
    free(s);
}

/*
A função topValue retorna o valor que está no topo da nossa stack.
*/

int topValue(Stack *s){
    if(s->top == NULL){
        return -1;
    }
    return s->top->element;
}

/*
A função lenght retorna o tamanho da minha stack.
*/

int lenght(Stack *s){
    return s->size;
}

int main(){

    return 0;
}

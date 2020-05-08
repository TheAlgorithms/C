#include <stdio.h>
#include <stdlib.h>
#include "STACK.h"
#define MAXLEN 50

int isOperator(char ch){
    if(ch=='*' || ch=='/' || ch=='%' || ch=='+' || ch=='-' || ch=='^'){
        return 1;
    }else{
        return 0;
    }
}

int getPrec(char ch){
    switch(ch){
        case '^': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return -1;
    }
}

void intopost(char *in,char *post){

    int i=0,j=0;
    char ch;
    STACK s;
    init(&s);

    while(in[i]!='\0'){
        if(in[i]=='(')
            push(&s,in[i]);
        else if(in[i]==')'){
            while((ch=pop(&s))!='('){
                post[j++]=ch;
            }
        }
        else if(isOperator(in[i])){
            while(getPrec(in[i])<=getPrec(peep(&s))){
                post[j++]=pop(&s);
            }
            push(&s,in[i]);
        }
        else{
            post[j++]=in[i];
        }
        i++;
    }
    while(ch=pop(&s)){
        post[j++]=ch;
    }
    post[j]='\0';
}

int main()
{
    char in[MAXLEN]="",post[MAXLEN]="";

    printf("Please enter infix expression:");
    gets(in);

    intopost(&in,&post);

    printf("Postfix : ");
    puts(post);

    return 0;
}

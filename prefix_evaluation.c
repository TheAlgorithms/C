#include<stdio.h>
#include<string.h>
#define MAX 50    
  
struct Stack
{          
int stack[MAX];                                                                                 //A Global Stack
char prefix[MAX];                                                                               //A Global Prefix Stack
}eval;     

int top=-1;
void pushstack(int tmp);                                                                        //push function
void evaluate(char c);                                                                          //Evaluiate Function


int main()
{ 

    int i,length;
    printf("Insert a prefix notation ::\n");
    scanf("%s",eval.prefix);
    length=strlen(eval.prefix);                                                                  //Length Of the Whole Prefix Expression To Evaluate
    for(i=length-1;i>=0;i--)
    {
        if(eval.prefix[i]>='0' && eval.prefix[i]<='9')
        {
          pushstack(i);                                                                           //if the element is a number push it
        }
        if(eval.prefix[i]=='+' || eval.prefix[i]=='-' || eval.prefix[i]=='*' || eval.prefix[i]=='/' || eval.prefix[i]=='^')       //if element is an operator
        {
          evaluate(eval.prefix[i]);                                                                                               //pass it to the evaluate
        }
    }                                                                                        
   printf("\n\nResult :: %d\n",eval.stack[top]);                                                                                  //print the result from the top
}

void pushstack(int tmp)                                                                                                           //definiton for push
{
   top++;                                                                                                                         //incrementing top
   eval.stack[top]=(int)(eval.prefix[tmp]-48);                                                                                    //type casting the string to its integer value
}

void evaluate(char c)                                                                          
{
   int storetop,newtop,ans;          
   storetop=eval.stack[top];                                                                                                       //storetop takes the value stored in the top
   eval.stack[top]='\0';                                                                                                           //make the stack top NULL as its a string
   top--;                                                                                                                          
   newtop=eval.stack[top];                                                                                                         //put the value at new top to newtop
   eval.stack[top]='\0';                                                                                                           //make it NULL
   top--;                                                                                     
   switch(c)                                                                                                                       //check operator been passed to evaluate
   {
      case '+':                                                                                
          ans=storetop+newtop;
          break;
      case '-':                                                                               
          ans=storetop-newtop;
          break;
      case '*':                                                                                
          ans=storetop*newtop;
          break;
      case '/':                                                                               
          ans=storetop/newtop;
          break;
      case '^':                                                                               
          ans=storetop^newtop;
          break;
      default:  
          ans=0;                                                                              
   }    
   top++;                                                                                  
   eval.stack[top]=ans;                                                                                                              //store the answer at top
}


    

    


#include<stdio.h>
#include<math.h>

   double Adjacent, Opposite, Hypotenuse;
   void Hypo();
   void Adj();
   void Opp();
   
int main(void)
{   
    int ch;
    
    //Input Adjacent, Opposite, Hypotenuse
    printf("Input Adjacent: ");
    scanf("%lf", &Adjacent);
    printf("Input Opposite: ");
    scanf("%lf", &Opposite);
    printf("Input Hypotenuse: ");
    scanf("%lf", &Hypotenuse);

do{
    printf("\n");
   printf("======================\n");
   printf("#1 Hypotenuse result\n");
   printf("#2 Adjacent result\n");
   printf("#3 Opposite result\n");
   printf("#4 Exit\n");
   printf("======================\n");
   printf("Please choose the result: ");
   scanf("%d", &ch);
   
   switch(ch){
      case 1:
      Hypo();
      break;

      case 2:
      Adj();
      break;

      case 3:
      Opp();
      break;
   }
   }while(ch > 0 && ch < 4);

   return 0;
}

void Hypo(){
   //Hypotenuse
   double Hypo = (pow(Adjacent,2)) + (pow(Opposite,2));
   Hypo = sqrt(Hypo);
   printf("\nHypotenuse: %lf",Hypo);
}

void Adj(){
   //Adjacent
   double Adj = (pow(Hypotenuse,2)) - (pow(Opposite,2)) ;
   Adj = sqrt(Adj);
   printf("\nAdjacent: %lf",Adj);
}

void Opp(){
   //Opposite
   double Opp = (pow(Hypotenuse,2)) - (pow(Adjacent,2));
   Opp = sqrt(Opp);
   printf("\nOpposite: %lf",Opp);
}
#include<stdio.h>
#include<math.h>

int main(void)
{
   double Adjacent=2, Opposite=3, Hypotenuse=4;
   
   //Hypotenuse
   double Hypo = (pow(Adjacent,2)) + (pow(Opposite,2));
   Hypo = sqrt(Hypo);
   printf("\nHypotenuse: %lf",Hypo);
   
   //Adjacent
   double Adj = (pow(Hypotenuse,2)) - (pow(Opposite,2)) ;
   Adj = sqrt(Adj);
   printf("\nAdjacent: %lf",Adj);
   
   //Opposite
   double Opp = (pow(Hypotenuse,2)) - (pow(Adjacent,2));
   Opp = sqrt(Opp);
   printf("\nOpposite: %lf",Opp);
   return 0;
}
#include <stdio.h>

int  decToBCD (int Decimal)
{
   return (((Decimal/10) << 4) | (Decimal % 10));
}

long long decToBin(int n){
    long long binaryNumber = 0;
    int remainder, i = 1, step = 1;
    while (n!=0){
        remainder = n%2;
        n /= 2;
        binaryNumber += remainder*i;
        i *= 10;
    }
    return binaryNumber;
}

int main(){
  int k;
  printf("Enter a decimal integer : ");
  scanf("%d",&k);
  int DecBCD = decToBCD(k);
  long long trueBCD = decToBin(DecBCD);
  printf("The BCD equivalent of %d is %d i.e. %lld\n",k,DecBCD,trueBCD);

}

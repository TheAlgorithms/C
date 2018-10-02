/*Program to convert from any base to another base as long as the base is less than 10*/

#include<stdio.h>
int main()
{
    int inp=0,baseold=0,basenew=0,mult_val = 1, dec = 0, dn = 0;
    scanf("%d %d %d",&inp,&baseold,&basenew);           //user defined input
        while (inp != 0) {
            dec = dec + (inp % 10) * mult_val;          
            mult_val *= baseold;
            inp /= 10;
        }
        mult_val = 1;
        while (dec != 0) {
            dn = dn + (dec % basenew) * mult_val;
            mult_val *= 10;
            dec /= basenew;
        }
        printf("%d\n",dn);              //displaying the output, can be very well be returned
        return 0;
}

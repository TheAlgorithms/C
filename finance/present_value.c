/*
Program to calculate the present value based
on defined cash flows and discount rate
The first cf in the list is at t = 0, thus
its nominal value = pv
There has to be at least one cash flow
*/

#include <stdio.h>
#include <math.h>
int present_value(float cash_flows[], float discount_rate, int number_of_cash_flows)
{
    if (number_of_cash_flows < 1)
    {
        printf("There must be at least one cash flow");
        return 0;
    }
    else
    {
        float present_value_of_cash_flows = cash_flows[0];
        for (int t = 1; t < number_of_cash_flows; t++)
        {
            present_value_of_cash_flows = present_value_of_cash_flows +
                    (cash_flows[t] / pow((1+discount_rate),t));
        }
        printf("The present value of the given cf is: \n");
        printf("%f",present_value_of_cash_flows);
        return 0;
    }
}

int main() {
    int number_of_cash_flows = 4;
    float cash_flows[] = {-200, 50,50,125};
    float discount_rate = 0.05;
    present_value(cash_flows,discount_rate,number_of_cash_flows);
    return 0;
}


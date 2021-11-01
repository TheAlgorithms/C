int divide(int dividend, int divisor)
{
    int sign = 1;
    long int output = 0;
    if (dividend < 0)
    {
        sign *= -1;
    }
    else
    {
        dividend *= -1;
    }
    if (divisor < 0)
    {
        sign *= -1;
    }
    else
    {
        divisor *= -1;
    }
    while (dividend <= divisor)
    {
        long int tmp = 0;
        long int div = divisor;
        while (dividend <= div)
        {
            tmp += (tmp + 1);
            dividend -= div;
            div += div;
        }
        if (output >= INT_MAX)
        {
            if (sign == -1)
            {
                return INT_MIN;
            }
            else
            {
                return INT_MAX;
            }
        }
        output += tmp;
    }

    return output * sign;
}

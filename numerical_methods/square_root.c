/**
 * @brief [Newton–Raphson method](https://en.wikipedia.org/wiki/Newton%27s_method)
 * @author [Mateus Nunes](https://github.com/mateusnssp)
 */

double f_abs(double n)
{
    /*returns the absolute value of n*/
    if (n >= 0.0){return n;}else{return -n;}
}

double f_sqrt(double n)
{
    /*returns the square root of n*/
    double r, aux;
    r = n / 2;
    int c = 1;
    double precision = precision; // Use this variable to determine the decimal precision of the result.
    while (c == 1)
    {
        aux = r;
        r = (r * r + n) / (2 * r);
        
        if (!f_abs(r - aux) > precision)
        {
            c = 0;
        }
    }
    
    return r;
}


void main()
{
    // Test/example

    double square_root = f_sqrt(2);
}

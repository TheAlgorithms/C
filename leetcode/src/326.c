bool isPowerOfThree(int n)
{
    long long int total = 3;
    if (n == 1)
        return true;
    else if (n < total)
        return false;
    else if (n == total)
        return true;
    while (total < n)
    {
        total *= 3;
    }
    if (total == n)
        return true;
    else
        return false;
}

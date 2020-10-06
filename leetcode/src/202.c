int numSquareSum(int n)
{ 
    int squareSum = 0;
    while (n)
    { 
        squareSum += (n % 10) * (n % 10); 
        n /= 10; 
    }
    return squareSum; 
}

bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do
    {
        slow = numSquareSum(slow);
        fast = numSquareSum(numSquareSum(fast));
    } 
    while (slow != fast);
    return (slow == 1); 
}

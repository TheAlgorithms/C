// Given n coins, find out how many rows can be filled with them if each row has
// one more coin than the last (starting from 1 coin. Last row may or may not be
// full)
int arrangeCoins(int n)
{
    // We need to find the point where n(n + 1) / 2 is just bigger than input -
    // that minus 1 is our answer, since the sum will be that number. So we will
    // use binarySearch for it
    int low = 1, high = 10e5;  // 10e5 square is bigger than constraints
    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long int guess = mid * (mid + 1L) / 2;
        long long int prevGuess = (mid - 1L) * mid / 2;
        if (guess == n)
        {  // Edge case - if it's equal then the last row is full and we have
           // reached our answer
            return mid;
        }
        else if (guess > n && prevGuess < n)
        {
            return mid - 1;
        }
        else if (guess > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;  // Return -1 to satisfy the compiler although early exit via
                // `return` is guaranteed by problem constraints
}

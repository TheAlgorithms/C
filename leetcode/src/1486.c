int xorOperation(int n, int start)
{
    int ans = start;
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ (start + 2 * i);
    }
    return ans;
}

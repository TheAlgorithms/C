int repeatedNTimes(int* A, int ASize)
{
    int count = (ASize / 2) - 1;
    int ans;

    for (int i = 0; i < ASize; i++)
    {
        int check = 0;
        for (int j = i + 1; j < ASize; j++)
        {
            if (A[i] == A[j])
            {
                check++;
            }
        }
        printf("%d\n", check);
        if (check == count)
        {
            ans = A[i];
            break;
        }
    }
    return ans;
}

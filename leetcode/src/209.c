/**
 * First, find the shortest array that begins with the first number.
 * The beginning and ending intexs of this array are head and tail.
 * Then, get the minimal length of the arraies that ends at tail + 1, tail + 2,
 * ... , numsSize - 1. The smallest of all lengths is the answer.
 */
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int sum = 0, head = 0, tail = 0, length = 0;
    while (tail < numsSize)
    {
        sum += nums[tail];
        tail++;
        if (sum >= target)
        {
            break;
        }
    }
    if (sum < target)
    {
        return 0;
    }
    while (sum - nums[head] >= target)
    {
        sum -= nums[head];
        head++;
    }
    length = tail - head;
    while (tail < numsSize)
    {
        sum += nums[tail];
        tail++;
        while (sum - nums[head] >= target)
        {
            sum -= nums[head];
            head++;
        }
        if (tail - head < length)
        {
            length = tail - head;
        }
    }
    return length;
}

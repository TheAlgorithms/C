/** We use binary search to find the local minimum efficiently
 * If middle element is greater than any of its neighbors, it is a peak element
 * ELse, if element on right is greater, a peak element on right must exist as numbers either increase to a point and decrease (which
 * is the peak) or continuously increase to the end of the array, which is then the peak.
 * Same if element on left is greater
 */
int findPeakElement(int* nums, int numSize)
{
    int i, mid, start = 0, end = numSize - 1;
    /**
     * Handle the edge case with single element first
	 */
    if (numSize == 1)
	{ 
        return 0;
    }
    while (start <= end)
	{
        mid = (start + end) / 2;
        /**
         * First, we check and ensure that there is no out of bounds case first, which can happen if only 2 elements are there
         * If we enter the next if block, we are at rightmost edge so we need only be greater than left element
         * If we enter the 3rd if block, we are at leftmost edge so we need only be greater than right element
         * After that, both blocks are checked to see which half to go to
         * Finally if start = end = mid, we return that as answer is guaranteed to exist as per the constraints
         */
        if (mid - 1 >= 0 && nums[mid - 1] < nums[mid] && mid + 1 < numSize && nums[mid] > nums[mid + 1]) 
		{ 
            return mid;
        }
        else if (mid + 1 == numSize && nums[mid] > nums[mid - 1])
		{ 
            return mid;
        }
        else if (mid - 1 < 0 && nums[mid] > nums [mid + 1])
		{ 
            return mid;
        }
        else if (nums[mid + 1] > nums[mid])
		{
            start = mid + 1;
        }
        else
		{
            end = mid - 1;
        }
    }
    return mid;
}

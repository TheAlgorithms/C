//We use binary Search to find the local minimum
//If middle element is greater than any of its neighbors, it is a peak element
//ELse, if element on right is greater, a peak element on right must exist as numbers either increase to a point and decrease (which
//is the peak) or continuously increase to the end of the array, which is then the peak
//Same if element on left is greater
int findPeakElement(int* nums, int numSize)
{
    int i, mid, start = 0, end = numSize - 1;
    if (numSize == 1) // Handle edge case first
	{ 
        return 0;
    }
    while (start <= end)
	{
        mid = (start + end) / 2;
        // We check that there is no out of bounds case first
        if (mid - 1 >= 0 && nums[mid - 1] < nums[mid] && mid + 1 < numSize && nums[mid] > nums[mid + 1]) 
		{ 
            return mid;
        }
        else if (mid + 1 == numSize && nums[mid] > nums[mid - 1]) // At rightmost edge
		{ 
            return mid;
        }
        else if (mid - 1 < 0 && nums[mid] > nums [mid + 1]) // At leftmost edge
		{ 
            return mid;
        }
        else if (nums[mid + 1] > nums[mid]) // Start checking in right half
		{
            start = mid + 1;
        }
        else // Start checking in left half
		{
            end = mid - 1;
        }
    }
    return mid; // If start = end = mid, return that as answer is guaranteed to exist as per the constraints
}

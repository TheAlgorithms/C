/**
 * Time complexity: O(log n).
 * Space complexity: O(1).
 * @details The array has a pattern that consists in of the existing sub-array to 
 *          the left of the non-repeating number will satisfy the condition that 
 *          each pair of repeated elements have their first occurrence at the even index
 *          and their second occurrence at the odd index, and that the sub-array to 
 *          the right of the non-repeating number will satisfy the condition that 
 *          each pair of repeated elements have their first occurrence at the odd index
 *          and their second occurrence at the even index. With this pattern in mind, 
 *          we can solve the problem using binary search.
 */

int singleNonDuplicate(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (right + left) / 2;
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1])
                left = mid + 2;
            else
                right = mid;
        }
        else {
            if (nums[mid] == nums[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return nums[left];
}

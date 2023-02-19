/**
 * Time complexity: O(log n).
 * Space complexity: O(1).
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

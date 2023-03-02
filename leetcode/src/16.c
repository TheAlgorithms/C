#include <stdlib.h> // for qsort()

int cmp(const void* a, const void* b) {
    const int *A = a, *B = b;
    return (*A > *B) - (*A < *B);
}

int threeSumClosest(int* nums, int nums_size, int target) {
    int i, j, k, result, sum3;
    qsort(nums, nums_size, sizeof(int), cmp);
    result = nums[0] + nums[1] + nums[2];
    for (i = 0; i < nums_size - 2; i++) {
        j = i + 1;
        k = nums_size - 1;
        while (j < k) {
            sum3 = nums[i] + nums[j] + nums[k];
            if (abs(target - sum3) < abs(target - result)) {
                result = sum3;
            }
            if (sum3 < target) {
                j++;
            } else if (sum3 > target) {
                k--;
            } else {
                return sum3;
            }
        }
    }
    return result;
}

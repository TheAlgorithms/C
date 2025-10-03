int *productExceptSelf(int *nums, int n, int *returnSize) {
    int totalProd = 1, prefProd = 1, count0 = 0;

    // Count zeros and calculate product of non-zero elements
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            count0++;
        } else {
            totalProd *= nums[i];
        }
    }

    int *res = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            prefProd *= nums[i];
        }
        if (count0 > 1) {
            res[i] = 0;
        } else {
            if (count0 == 0) {
                res[i] = (totalProd / prefProd) * (prefProd / nums[i]);
            } else {
                if (nums[i] == 0) {
                    res[i] = (totalProd / prefProd) * (prefProd);
                } else {
                    res[i] = 0;
                }
            }
        }
    }
    *returnSize = n;
    return res;
}

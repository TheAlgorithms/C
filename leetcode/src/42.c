#define max(x,y)(((x)>(y))?(x):(y))
#define min(x,y)(((x)<(y))?(x):(y))

// Max stack. Runtime: O(n), Space: O(n)
// Algorithm description: 
// - Calculate the stack of maximums from right board.
// - For each index find left maximum and right maximum of height
// - The each index if heights could place nor greater than minimum of left and right max minus curr height
// - Sum all index in result
int trap(int* height, int heightSize){
    int* rightMaxStack = malloc(heightSize * sizeof(int));
    rightMaxStack[heightSize - 1] = height[heightSize - 1];

    for (int i = heightSize - 2; i >= 0; i--){
        rightMaxStack[i] = max(rightMaxStack[i + 1], height[i]);
    }

    int leftMax = 0;
    int result = 0;
    for (int i = 0; i < heightSize; i++){
        leftMax = max(leftMax, height[i]);
        result += max(0, min(leftMax, rightMaxStack[i]) - height[i]);
    }
    
    free(rightMaxStack);
    return result;
}

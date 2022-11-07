int max(int a, int b){
    if (a > b){
        return a;
    }
    
    return b;
}

int min(int a, int b){
    if (a > b){
        return b;
    }
    
    return a;
}

// Max stack. Runtime: O(n), Space: O(n)
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
    
    return result;
}
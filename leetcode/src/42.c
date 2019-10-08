

int trap(int* height, int heightSize){
    // left[i] contains height of tallest bar to the 
    // left of i'th bar including itself
    if(heightSize==0)
        return 0;
    int left[heightSize]; 
  
    // Right [i] contains height of tallest bar to 
    // the right of ith bar including itself 
    int right[heightSize]; 
  
    // Initialize result 
    int water = 0; 
  
    // Fill left array 
    left[0] = height[0]; 
    for (int i = 1; i < heightSize; i++) 
       left[i] = left[i-1]>height[i]?left[i-1]:height[i]; 
  
    // Fill right array 
    right[heightSize-1] = height[heightSize-1]; 
    for (int i = heightSize-2; i >= 0; i--) 
       right[i] = right[i+1]>height[i]?right[i+1] : height[i]; 
  
    // Calculate the accumulated water element by element 
    // consider the amount of water on i'th bar, the 
    // amount of water accumulated on this particular 
    // bar will be equal to min(left[i], right[i]) - arr[i] . 
    for (int i = 0; i < heightSize; i++) 
       water += (left[i]>right[i]?right[i]:left[i]) - height[i]; 
  
    return water; 

}


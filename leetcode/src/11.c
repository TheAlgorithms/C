int maxArea(int* height, int heightSize){
	int l = 0; 
    int r = heightSize -1; 
    int area = 0; 
    int small_height=0;
    
    while (l < r) 
    { 
        // Calculating the smaller height
        small_height=height[l]>height[r] ? height[r] : height[l];
         // Calculating the area
        area = area>small_height* (r - l) ? area : small_height* (r - l); 
                          
            if (height[l] < height[r]) 
                l += 1; 
                  
            else
                r -= 1; 
    } 
    return area; 

}
//Fucntion to calculate min of values a and b
int min(int a, int b){
    return ((a<b)?a:b);
}

//Two pointer approach to find maximum container area
int maxArea(int* height, int heightSize){

    //Start with maximum container width
    int start = 0;
    int end = heightSize-1;
    int res = 0;

    while(start<end){
        //Calculate current area by taking minimum of two heights
        int currArea = (end-start)*min(height[start],height[end]);
        
        if(currArea>res)
            res = currArea;

        if(height[start]<height[end])
            start = start + 1;
        else
            end = end - 1;
            
    }
    
    return res;
    
}

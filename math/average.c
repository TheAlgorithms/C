/**
 * @brief    This function calculates the average of an array
 * @param avg[]
 * @return avg_val
 */
#include <stdio.h>
#include <assert.h>

//average of an array

double average(int avg[]) {
    double result = 0;
    int size=0;
    
    while(avg[size]!='\0'){
        size++;
    }
    
    if(size==0){
        printf("\n Empty array");
        return 0;
    }

    for (int i = 0; i < size; i++) {
        result += avg[i];
    }

    int avg_val = result / size;
    
    return avg_val;
}

/**
 * Test function
 * @return void
 */
void test()
{
    int test_0[] = {1,2,3,4,5};
    assert(average(test_0)==3);
    
    int test_1[] = {-1,-2,-3,-4,-5};
    assert(average(test_1)==-3);
    
    int test_2[] = {-1,2,3,-4,0};
    assert(average(test_2)==0);
    
    int test_3[] = {};
    assert(average(test_3)==0);
}

/**
 * Driver Code
 * @return None
 */
int main()
{
    test();
    return 0;
}

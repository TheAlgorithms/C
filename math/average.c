#include <stdio.h>
#include <assert.h>

//average of an array

double average(int avg[]) {
    double result = 0;
    int size=0;
    
    while(avg[size]!='\0'){
        size++;
    }

    for (int i = 0; i < size; i++) {
        result += avg[i];
    }

    return result / size;
}

/**
 * Test function
 * @return void
 */
void test()
{
    int test[] = {1,2,3,4,5};
    assert(average(test)==3);
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

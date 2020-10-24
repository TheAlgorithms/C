/**
 * @file
 * @brief [Prime Seive](https://leetcode.com/problems/count-primes/)
 * algorithm implementation.
 * @author[Divyansh Kushwaha](https://www.github.com/webdesignbydivyansh)
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @addtogroup misc
 * @{
 */
/**
 * Prime Sieve works in O(nlogn) time
 * @param p array to be updated
 */
void prime(int *p)
{
	for(long long int i=3;i<=1000000;i+=2)
	p[i]=1;
	for(long long int i=3;i<=1000000;i+=2)
	{
		if(p[i]==1)
		for(long long int j=i*i;j<=1000000;j+=i)
		p[j]=0;
	}
	p[2]=1;
	p[0]=p[1]=0;    
}
/**
 * Count func counts the number of 
 * prime numbers.
 */
int count(int *arr, const int size){
  int k=0;
  for(int i=0;i<=size;i++){
    if(arr[i]==1){
      k++;
    }
  }
  return k;
}

/**@Test function
 * @brief Test implementations
  * @returns void
  */
static void test()
{
    // Test Case 1
    const int size = 10; /* array size */
    printf("Test Case 1...");
    int arr[1000000];   /* array to store prime numbers */
    prime(arr);
    assert(count(arr,size)==4);
    printf("Passed\n");

}

/** @brief Main function
 *  @param argc commandline argument count (ignored)
 *  @param argv commandline array of arguments (ignored)
 *  @returns 0 on exit
 */
int main(int argc, const char *argv[])
{
    test();	//execute the test
    return 0;
}

/**
 * @file
 * @brief [Prime Seive](https://leetcode.com/problems/count-primes/)
 * algorithm implementation.
 * @author[Divyansh Kushwaha](https://github.com/webdesignbydivyansh)
 */
#include <assert.h>	/// for assert
#include <stdio.h>	/// for standard input output
#include <stdlib.h>	/// for general purpose standard library

/**
 * @addtogroup misc
 * @{
 */
/**
 * @brief Prime Sieve works in O(nlogn) time
 * @param p array to be updated
 * @param size denotes the number upto which prime numbers are to be found
 * @returns null
 */
void prime(int *p, const int size)
{
	for(long long int i=3;i<=size;i+=2)
	p[i]=1;
	for(long long int i=3;i<=size;i+=2)
	{
		if(p[i]==1)
		for(long long int j=i*i;j<=size;j+=i)
		p[j]=0;
	}
	p[2]=1;
	p[0]=p[1]=0;    
}
/**
 * @brief Count func counts the number of 
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

/**
 * @brief Test implementations
  * @returns void
  */
static void test()
{
    // Test Case 1
    const int size = 10; /* array size */
    printf("Test Case 1...");
    int arr[size];   /* array to store prime numbers */
    for(int i=0;i<=size;i++)
    arr[i]=0;
    prime(arr,size);
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
    test();	// execute the tests
    return 0;
}

/**
 * @file
 * @brief [Prime Sieve](https://leetcode.com/problems/count-primes/)
 * algorithm implementation.
 * @author [Divyansh Kushwaha](https://github.com/webdesignbydivyansh)
 */
#include <assert.h>	/// for assert
#include <stdio.h>	/// for standard input output
#include <stdlib.h>	/// for general purpose standard library

const unsigned long long MAX_SIZE = 1000000;  /// variable upto which prime numbers are to be found out
/**
 * @addtogroup misc
 * @{
 */
/**
 * @brief Prime Sieve works in O(nlogn) time
 * @param p array to be updated
 * @returns void
 */
void prime(int *p)
{
	for(long long int i=3;i<=MAX_SIZE;i+=2) { p[i]=1; }
	for(long long int i=3;i<=MAX_SIZE;i+=2)
	{
		if(p[i]==1) {
		    for(long long int j=i*i;j<=MAX_SIZE;j+=i) {
			p[j]=0;
		    }
		}
	}
	p[2]=1;
	p[0]=p[1]=0;    
}
/**
 * @brief Count func counts the number of 
 * prime numbers.
 * @param arr contains the prime numbers
 * @param size denotes upto which prime numbers are to be found out
 * @returns count of prime numbers
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
    int arr[1000005]={0};   /* array to store prime numbers */
    prime(arr);
    assert(count(arr,size)==4);
    printf("Passed\n");
}

/** 
 * @brief Main function
 * @param argc commandline argument count (ignored)
 * @param argv commandline array of arguments (ignored)
 * @returns 0 on exit
 */
int main(int argc, const char *argv[])
{
    test();	// execute the tests
    return 0;
}

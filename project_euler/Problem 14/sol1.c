#include <stdio.h>
#include <stdlib.h>

#ifdef _OPENMP
    #include <omp.h>
    #pragma message ("Using OpenMP parallelization")
#else
    #pragma message ("Not using OpenMP parallelization")
#endif

/**
 * Computes the length of collatz sequence for a given 
 * starting number 
 **/
long long collatz(long long start_num)
{
    long long length = 1;
    
    while (start_num != 1)      /* loop till we reach 1 */
    {
        if(start_num & 0x01)    /* check for odd */
            start_num = 3 * start_num + 1;
        else
            start_num >>= 1;    /* simpler divide by 2 */
        length ++;
    }

    return length;
}

int main(int argc, char **argv)
{
    long long max_len = 0, max_len_num = 0;
    long long MAX_NUM = 1000000;

    if (argc == 2)  /* set commandline argumnet as the maximum iteration number */
    {
        MAX_NUM = atoll(argv[1]);
        printf("Maximum number: %lld\n", MAX_NUM);
    }

    /** 
     * Since the computational values for each iteration step are independent, 
     * we can compute them in parallel. However, the maximum values should be 
     * updated in synchrony so that we do not get into a "race condition".
     * 
     * To compile with supporintg gcc or clang, the flag "-fopenmp" should be passes
     * while with Microsoft C compiler, the flag "/fopenmp" should be used.
     * 
     * Automatically detects for OPENMP using the _OPENMP macro.
     **/
    #ifdef _OPENMP
    #pragma omp parallel for shared(max_len, max_len_num) schedule(guided)
    #endif
    for (long long i = 1; i < MAX_NUM; i++)
    {
        long long L = collatz(i);
        if (L > max_len)
        {
            max_len = L;        /* length of sequence */
            max_len_num = i;    /* starting number */
        }

        #if defined(_OPENMP) && defined(DEBUG)
        printf("Thread: %2d\t %3lld: \t%5lld\n", omp_get_thread_num(), i, L);
        #elif defined(DEBUG)
        printf("%3lld: \t%5lld\n", i, L);
        #endif
    }

    printf("Start: %3lld: \tLength: %5lld\n", max_len_num, max_len);

    return 0;
}
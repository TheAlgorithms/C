#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t main()
{
	/* find and sum all primes below 2M with the sieve of Eratosthenes. */
	uint64_t N = 2000000, sum = 0, i;
	uint8_t *sieve = (uint8_t*)calloc(N, sizeof(uint8_t));
	for (i = 0; i < N; ++i) sieve[i] = 1;

	for (i = 2; i < N; ++i) /* start at 2 because 1 is not prime */
	{
		if (sieve[i-1])
		{
			sum += i;
			for (uint64_t j = 2*i; j < N+1; j += i)
				sieve[j-1] = 0;
		}
	}

	printf("%" PRIu64 "\n", sum);
	free(sieve);
	return 0;
}

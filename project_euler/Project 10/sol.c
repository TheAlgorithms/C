/* Project Euler
 * Problem 10
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million. */

/* Determine if an integer num is a prime number, returns:
 * 1 if prime
 * 0 otherwise */
int isPrime(int num) {
  // Base case
  if ((num <= 1) || (num % 2 == 0 && num > 2)) {
    return 0;
  } else {
    /* Iterates over all numbers from 3 (the first prime number) up to num / 2,
     * breaks the loop and returns 0 if any of these numbers is a divisor of num
     */
    for (int i = 3; i < num / 2; i += 2) {
      if (num % i == 0)
        return 0;
    }
  }

  return 1;
}

/* Iterates over integers from 3 (the first prime number) up to two million and
 * returns the sum of the primes in the interval */
int primeSum() {
  int sum = 0;

  /* Iterates over all numbers from 3 (the first prime number) up to two million
   * adding all primes to the sum variable */
  for (int i = 3; i < 2000000; i++) {
    sum = isPrime(i) ? sum + i : sum;
  }

  return sum;
}

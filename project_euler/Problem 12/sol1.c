#include <stdio.h>

static unsigned divisor_count(unsigned long n);

unsigned divisor_count(unsigned long n)
{
  unsigned ret = 1;
  unsigned long j;

  for (j = 2; j <= n; j++) {
    unsigned c = 0;
    while (n % j == 0) {
      c++;
      n /= j;
    }
    ret *= c+1;
  }
  return ret;
}

int main(void)
{
  unsigned long i = 1;
  unsigned long n = 1;

  while (divisor_count(n) < 500) {
    n += ++i;
  }

  printf("%lu\n", n);
  
  return 0;

}


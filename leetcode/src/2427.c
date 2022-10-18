int commonFactors(int a, int b) {

  int n = fmin(a, b);
  /* suppose two numbers be 6 and 18.so max number which can divide both
  must be less than or equal to minimum of the two number i.e 6*/

  int count = 0; // to keep count of common divisers
  for (int i = 1; i <= n; i++) {
    if (a % i == 0 && b % i == 0) {
      count++;
    }
  }
  return count;
}

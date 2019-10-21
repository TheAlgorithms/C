#include <stdlib.h>

/* Compares two arrays of the same length and returns:
 * 0 if they aren't equal
 * 1 if they are equal */
int equalArrays(const int *arr_a, const int *arr_b, size_t arr_len) {
  for (int i = 0; i < arr_len; i++) {
    /* Compare the elements at position i in each array and return false if they
     * aren't equal */
    if (arr_a[i] != arr_b[i]) {
      return 0;
    }
  }

  return 1; // Comparison ended and all elements are equal
}

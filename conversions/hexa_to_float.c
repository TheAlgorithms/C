#include <stdint.h>
#include <stdio.h>

int main(void) {
  char myString[]="0x3f9d70a4";
  uint32_t num;
  float f;
  sscanf(myString, "%x", &num);  // assuming you checked input
  f = *((float*)&num);
  printf("the hexadecimal 0x%08x becomes %.3f as a float\n", num, f);
}
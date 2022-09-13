#include <stdio.h>
#include <limits.h>
#include <float.h>

// the values was taken from en.wikipedia.org/wiki/C_data_types

int main() {
  int a = INT_MAX;
  unsigned short int b = USHRT_MAX;
  signed long int c = LONG_MAX;
  float d = FLT_MAX;
  double e = DBL_MAX;

  printf("------------------\nInteger variable:\n-size: %lu bytes\n-max value: %i\n", sizeof(a), a);
  printf("------------------\nUnsigned short integer variable:\n-size: %lu bytes\n-max value: %hu\n", sizeof(b), b);
  printf("------------------\nSigned long int variable:\n-size: %lu bytes\n-max value: %li\n", sizeof(c), c);
  printf("------------------\nFloat variable:\n-size: %lu bytes\n-max value: %f\n", sizeof(d), d);
  printf("------------------\nDouble variable:\n-size: %lu bytes\n-max value: %lf\n", sizeof(e), e);
}

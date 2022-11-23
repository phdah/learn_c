// https://www.codewars.com/kata/560a4962c0cc5c2a16000068/train/c
#include <stdio.h> // printf
#include <stdlib.h> // atoi
#include <math.h> // pow

unsigned eq_sum_powedig(const unsigned h_max, const unsigned expo)
{
  // 110 / 10 = 11 % 10 = 1
  unsigned i=h_max;
  unsigned out=0;
  int j;
  while ( i > 0 ) {
    j = i % 10;
    out += pow(j, expo);
    i /= 10;

  }
  return out;
}

int main(int argc, char** argv)
{

  size_t max_val = atoi(argv[1]);
  int expo = atoi(argv[2]);

  printf("max_val: %zu\n", max_val);
  printf("expo: %d\n\n", expo);

  unsigned short len_of_value=0;
  unsigned long c=max_val;
  while ( c > 0) {
    len_of_value++;
    c /= 10;
  }

  printf("len_of_value: %u\n", len_of_value);
  size_t upper_limit = pow(9, expo) * len_of_value;
  printf("upper_imit: %zu\n\n", upper_limit);
  size_t out;

  for (int value = 2; value <= upper_limit; value++){
    out = eq_sum_powedig(value, expo);

    if (out == value)
      printf("%zu\n", out);

  }

  return 0;

}


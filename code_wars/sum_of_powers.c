// https://www.codewars.com/kata/560a4962c0cc5c2a16000068/train/c
#include <stdio.h> // printf
#include <stdlib.h> // atoi
#include <math.h> // pow

unsigned eq_sum_powedig(const unsigned, const unsigned);

int main(int argc, char** argv)
{

  int max_val = atoi(argv[1]);
  int expo = atoi(argv[2]);
  printf("max_val: %d\n", max_val);
  printf("expo: %d\n\n", expo);

  for (int value = 2; value <= max_val; value++){
    eq_sum_powedig(value, expo);
  }
  return 0;

}

unsigned eq_sum_powedig(const unsigned h_max, const unsigned expo)
{
  // 110 / 10 = 11 % 10 = 1
  int i=h_max;
  int out=0;
  int j;
  while ( i > 0 ) {
    j = i % 10;
    out += pow(j, expo);
    i /= 10;

  }

  if (out == h_max) {
    printf("%d\n", out);
  }
}

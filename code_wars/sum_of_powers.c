// https://www.codewars.com/kata/560a4962c0cc5c2a16000068/train/c
#include <stdio.h> // printf
#include <stdlib.h> // atoi
#include <math.h> // pow

unsigned eq_sum_powedig(const unsigned, const unsigned);

void main(int argc, char** argv)
{

  int h_max = atoi(argv[1]);
  int expo = atoi(argv[2]);
  printf("h_max %d\n", h_max);
  printf("expo %d\n", expo);

  eq_sum_powedig(h_max, expo);

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

  printf("%d\n", out);
  return 0;
}

// https://www.codewars.com/kata/54c27a33fb7da0db0100040e
#include <stdbool.h> // bool
#include <math.h> // pow

#define n 16

bool main() {

  double root = sqrt(n);

  int root_int = (int)root;

  double decimals = root - root_int;

  return !decimals;

  }
}

// https://www.codewars.com/kata/515f51d438015969f7000013
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  // argv[0] is always name of program

  int argv_num = strtol(argv[1], '\0', 10);

  printf("%d\n", argv_num);
  printf("[ ");

  for (int i = 1; i <= argv_num; ++i) {
  // create a print function such that can be called with input

    printf("[");

    printf("1");

    printf("]");

  }
  printf(" ]");
  return 404;
}

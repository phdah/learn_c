// https://www.codewars.com/kata/58ee4db3e479611e6f000086
#include <stdio.h>

#define LENGTH_ARRAY 8
#define n 3

int shift_array_left(int* array, int left_one) {

  array[left_one + n - 1] = 0;
  array[left_one - 1] = 1;

  return 0;

}

void print_array(int* array, int length_array) {

  for ( int i = 0; i < length_array; i++)
    printf("%d", array[i]);

  printf("\n");
}

int main() {

  int array[LENGTH_ARRAY] = {0};

  int i;

  for ( i = 0; i < n; i++ )
    array[LENGTH_ARRAY-1-i] = 1;

  print_array(array, LENGTH_ARRAY);

  int left_one = LENGTH_ARRAY - n;
  while ( left_one ) {

    shift_array_left(array, left_one--);

    print_array(array, LENGTH_ARRAY);

  }

}

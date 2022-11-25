// https://www.codewars.com/kata/52fba66badcd10859f00097e/c
#include <stdio.h> // printf
#include <stdlib.h> // atoi

char string[10]="Hello End";

int valueInArray(int value, int* vowlArray) {

  for ( int i = 0; i < 10; i++ )
    if ( vowlArray[i]==value )
      return 0;

  return 1;

}

int main() {

  // all letters
  int array[10]={65};

  // all vowls
  array[1] += 65+4;
  array[2] += 65+8;
  array[3] += 65+14;
  array[4] += 65+20;
  array[5] += 65+32;
  array[6] += 65+32+4;
  array[7] += 65+32+8;
  array[8] += 65+32+14;
  array[9] += 65+32+20;

  for ( int i = 0; i < sizeof(string); i++ ) {
    if ( valueInArray(string[i], array) )
      printf("%c", string[i]);

  }
  printf("\n");

}

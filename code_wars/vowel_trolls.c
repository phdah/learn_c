// https://www.codewars.com/kata/52fba66badcd10859f00097e/c
#include <stdio.h> // printf

char string[10]="Hello End";

int isVowel(const char c, const int* array) {

  return (c > 96 ? array[c-97] : array[c-65]);

}

int main() {

  // all letters
  int array[26]={0};

  // all vowls
  array[0] = 1;
  array[4] = 1;
  array[8] = 1;
  array[14] = 1;
  array[20] = 1;

  for ( int i = 0; i < sizeof(string); i++ ) {
    if ( string[i] > 64 && string[i] < 91 || string[i] > 96 && string[i] < 123 ) {

      if ( !isVowel(string[i], array) )
        printf("%c", string[i]);

    } else {
      printf("%c", string[i]);

    }
  }
  printf("\n");

  return 0;
}

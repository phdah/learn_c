#include <stdio.h>
int j;
int p=0;

void main() {
  for ( int i = 0; i <= 50; ++i ) {
    j = i / 10;
    if ( j != p ) {

      printf("%d\n", j);
    }
    else {

      printf("Value already found.\n");

    }
    p = j;

  }
}

// https://adventofcode.com/2022/day/2
#include <stdio.h> // printf
#include <stdlib.h> // fopen, fgets, fclose

int calculateScore(int *myscore, int *opponent, int *me); // define function that depends on main calculations

int main(int argc, char** argv)
{

  FILE* ptr = fopen(argv[1], "r");
  char str[6];

  int opponent;
  int me;

  int myscore=0;

  while ( fgets(str, 6, ptr) != NULL ) {
    // 1 = rock, 2 = paper, 3 = scissors
    opponent = str[0]-64;
    me = str[2]-87;
    myscore += me; // add score for my choice

    calculateScore(&myscore, &opponent, &me);

  }
  printf("%d\n", myscore);

  return 0;
}

int calculateScore(int *myscore, int *opponent, int *me)
{
  // Opponent rock = 1
  if ( *opponent == 1 ) {
    if ( *me == 1 )
      *myscore += 3; // draw
    else if ( *me == 2)
      *myscore += 6; // victory
  }
  // Opponent paper = 2
  if ( *opponent == 2 ) {
    if ( *me == 2 )
      *myscore += 3; // draw
    else if ( *me == 3)
      *myscore += 6; // victory
  }
  // Opponent siccors = 3
  if ( *opponent == 3 ) {
    if ( *me == 3 )
      *myscore += 3; // draw
    else if ( *me == 1)
      *myscore += 6; // victory
  }
  return 0;
}

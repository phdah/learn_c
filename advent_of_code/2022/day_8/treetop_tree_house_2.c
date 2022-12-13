// https://adventofcode.com/2022/day/8
#include <stdio.h>
#include <stdlib.h>

#define str_l 101
#define map_l 99

int heightCheck(char map[map_l][map_l], int height, int width, int max_height, int max_width)
{

  int view=1;

  int i=1;


  // up
  while ( height-i >= 0 ) {
    if ( map[height][width] <= map[height-i][width] ) {
      ++i;
      break;
    }
    ++i;
  }
  view*=(i-1);
  i=1;
  // down
  while ( height+i < max_height ) {
    if ( map[height][width] <= map[height+i][width] ) {
      ++i;
      break;
    }
    ++i;
  }
  view*=(i-1);
  i=1;
  // left
  while ( width-i >= 0 ) {
    if ( map[height][width] <= map[height][width-i] ) {
      ++i;
      break;
    }
    ++i;
  }
  view*=(i-1);
  i=1;
  // right
  while ( width+i < max_width ) {
    if ( map[height][width] <= map[height][width+i] ) {
      ++i;
      break;
    }
    ++i;
  }
  view*=(i-1);


  return view;

}

int main(int argc, char** argv)
{

  FILE* ptr = fopen(argv[1], "r");
  char str[str_l];
  char map[map_l][map_l];

  int highest_scenic_score=0;
  int tree_scenic_score=0;

  int width=0;
  int height=1;

  fgets(str, str_l, ptr);

  while ( str[width] != '\n' ) {
    map[0][width] = str[width];
    ++width;
  }

  int i;

  while ( fgets(str, str_l, ptr) != NULL ) {
    i = 0;
    while ( i < width ) {
      map[height][i] = str[i];
      ++i;
    }
    ++height;
  }

  i=1;
  int j=1;

  while ( i < width-1 ) {
    while ( j < height-1 ) {
      tree_scenic_score = heightCheck(map, j, i, height, width);
      if ( tree_scenic_score >  highest_scenic_score ) {
         highest_scenic_score = tree_scenic_score;
      }
      ++j;
    }
    ++i;
    j=1;
  }
  printf("%d\n", highest_scenic_score);

  fclose(ptr);
  return 0;
}

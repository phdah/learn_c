// https://adventofcode.com/2022/day/9
#include <stdio.h>
#include <stdlib.h>

#define str_l 20
#define map_mid 10

typedef struct BridgePoint {
    unsigned int x;
    unsigned int y;
} BridgePoint;

void checkNewPosition(int map[map_mid*2][map_mid*2], int* visited, unsigned int* x, unsigned int* y)
{
    if ( map[*x][*y] == 0 ) {
        map[*x][*y]=1;
        ++*visited;
    }
}


void movePoint(int map[map_mid*2][map_mid*2], int* visited, BridgePoint* point, char dir, char part)
{
    // y: up and down
    if ( dir=='U' ) {
        ++point->y;
    }
    if ( dir=='D' ) {
        --point->y;
    }

    // x: right->and left
    if ( dir=='R' ) {
        ++point->x;
    }
    if ( dir=='L' ) {
        --point->x;
    }

    if ( part == 'T' ) {
        checkNewPosition(map, visited, &point->x, &point->y);
    }
}

void checkTail(int map[map_mid*2][map_mid*2], int* visited, BridgePoint* head, BridgePoint* tail, char dir)
{
    // check distance to head
    int head_x = head->x;
    int head_y = head->y;
    int tail_x = tail->x;
    int tail_y = tail->y;

    int dist = abs(head_x - tail_x) + abs(head_y - tail_y);
    //printf("dist %d\n ", dist);

    // move tail
    if ( dist > 1 ) {
        movePoint(map, visited, tail, dir, 'T');
    }

}

int main(int argc, char** argv)
{

    FILE* ptr = fopen(argv[1], "r");
    char str[str_l];
    char direction;
    char moves_char[str_l]={0};
    int moves;

    // initialize visited sum and map
    int visited=1;
    int map[map_mid*2][map_mid*2]={{0}};
    map[map_mid][map_mid]=1;

    // initialize head and tail position
    BridgePoint posHead;// = (BridgePoint*)malloc(sizeof(BridgePoint));
    posHead.x = map_mid;
    posHead.y = map_mid;

    BridgePoint old_posHead=posHead;
    printf("Original head: x=%d, y=%d", old_posHead.x, old_posHead.y);

    BridgePoint posTail;// = (BridgePoint*)malloc(sizeof(BridgePoint));
    posTail.x = map_mid;
    posTail.y = map_mid;

    int digit;

    while ( fgets(str, str_l, ptr) != NULL ) {
        direction=str[0];
        digit=2; // digit alwasy start on the 3rd byte
        while ( str[digit] != '\n' ) {
            moves_char[digit-2] = str[digit];
            ++digit;
        }
        moves = atoi(moves_char);

        printf("\nDir: %c, Moves: %d\n", direction, moves);
        printf("    Head: x=%d, y=%d\n", posHead.x, posHead.y);
        printf("    Tail: x=%d, y=%d\n", posTail.x, posTail.y);

        while ( moves > 0 ) {
            movePoint(map, &visited, &posHead, direction, 'H');

            printf("    Head: x=%d, y=%d\n", posHead.x, posHead.y);

            checkTail(map, &visited, &posHead, &posTail, direction);

            printf("    Tail: x=%d, y=%d\n", posTail.x, posTail.y);
            printf("Visited: %d\n", visited);

            --moves;
        }

    }
    printf("Original head: x=%d, y=%d", old_posHead.x, old_posHead.y);
    for ( int y=14; y > 9; y-- ) {
        for ( int x=10; x < 16; x++ ) {
        printf("%d", map[x][y]);
        }
        printf("\n");
    }

    digit=0;
    while ( str[digit] != '\n' ) {
        moves_char[digit] = 0;
        ++digit;
    }

    fclose(ptr);
    return 0;
}

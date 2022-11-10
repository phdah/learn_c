# include <stdio.h>

char hello_world[20] = "Hello World";
char name_input[10] = "Philip";

void printName(char* name) {

  printf("%s", name);
}

void main() {

  printf("%s ", hello_world);
  printName(name_input);

}


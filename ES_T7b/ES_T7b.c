#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main () {
  char input[80], output[80];
  fgets(input, 80, stdin);
  int i = 0;
  for (int l = strlen(input) - 2; l >= 0; l--) {
    input[l] = tolower(input[l]);
    output[i] = input[l];
    i += 1;
  }
  output[i] = '\0';
  for (int index = strlen(output) - 1;index >=0; index--) {
    if (output[index] != input[index]) {
      printf("Esta palavra nao e um palindromo\n");
      return 0;
    }
  }
  printf("Esta palavra e um palindromo\n");

  return 0;
}

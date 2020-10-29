#include <string.h>
#include <stdio.h>

int main () {
  char input[80], output[80];
  fgets(input, 80, stdin);
  int i = 0;
  for (int l = strlen(input) - 2; l >= 0; l--) {
    output[i] = input[l];
    i += 1;
  }
  output[i] = '\0';
  printf("%s\n", output);
  return 0;
}

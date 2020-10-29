#include <stdio.h>

int main () {
  int input = 0;
  scanf("%d", &input);
  if (input%2 > 0) {
    printf("impar\n");
    return 0;
  }
  printf("par\n");
  return 0;
}

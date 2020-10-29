#include <stdio.h>

int isOdd(int input);
void processInput();
int odd = 0, even = 0;

int main () {
  for (int i = 0; i < 10; i++) {
    processInput();
  }
  printf("%d pares , %d impares\n", even, odd);
  return 0;
}

int isOdd(int input){
  return input%2;
}

void processInput () {
  int input;
  scanf("%d", &input);
  if(isOdd(input)){
    odd+=1;
    return;
  }
  even+=1;
  return;
}

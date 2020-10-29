#include <stdio.h>
int factorial(int input);
int functionCombination(int n, int s);
int main() {
  int n,s;
  scanf("%d\n%d",&n,&s);
  printf("%d\n", functionCombination(n,s));
  return 0;
}

int factorial(int input) {
  int control = input;
  while(control > 1) {
    input*=--control;
  }
  return input == 0 ? 1 : input;
}

int functionCombination(int n, int s) {
  return factorial(n)/(factorial(s)*factorial(n-s));
}

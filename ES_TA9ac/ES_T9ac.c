#include <stdio.h>
float elevate (float num, int time);

int main () {
  float x, y, output;
  char c;
  scanf("%f%c%f", &x, &c, &y);
  switch (c) {
    case '-':
    output = x-y;
    break;
    case '+':
    output = x+y;
    break;
    case '/':
    output = x/y;
    break;
    case '*':
    output = x*y;
    break;
    case '^':
    output = elevate(x, y);
    break;
    default:
    return 0;
    break;
  }
  printf("%.3f\n", output );
  return 0;
}
float elevate (float num, int time) {
  float orig = num;
  for (int i = time; i > 1; i--) {
    num*=orig;
  }
  return num;
}

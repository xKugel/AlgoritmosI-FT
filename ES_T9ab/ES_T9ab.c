#include <stdio.h>
#include <math.h>

float media (float x, float y, char c);

float mediaA (float x, float y);

float mediaB (float x, float y);

int main () {
  float x, y;
  char c;
  scanf("%c", &c);
  scanf("%f %f", &x, &y);

  printf("%.3f\n", media(x, y, c));
  return 0;
}

float media (float x, float y, char c) {
  if (c == 'A'){
    return (y+x)/2;
  } else if (c == 'B') {
    return sqrt(x*y);
  } else {
    return 0;
  }
}

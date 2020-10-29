#include <stdio.h>
#include <math.h>

typedef struct tipo {
  float x,y;
} Tipo;

int main () {
  Tipo p1, p2;
  scanf("%f %f", &p1.x, &p1.y );
  scanf("%f %f", &p2.x, &p2.y );

  float detX = p1.x - p2.x;
  float detY = p1.y - p2.y;
  float d = sqrt((detX*detX) + (detY*detY));

  if(d < 0.00000001) {
    printf("os pontos sao iguais\n");
    return 0;
  }
  printf("os pontos nao sao iguais\n");

  return 0;
}

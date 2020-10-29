#include <stdio.h>
#include <math.h>

typedef struct tipo {
  int x,y;
} Tipo;

int main () {
  Tipo p1, p2, p3, p4;
  scanf("%i %i", &p1.x, &p1.y );
  scanf("%i %i", &p2.x, &p2.y );
  scanf("%i %i", &p3.x, &p3.y );
  scanf("%i %i", &p4.x, &p4.y );

  // Is ponto imparares dentro
  int isPI = p1.x <= p3.x && p1.y <= p3.y;
  // Is ponto parares dentro
  int isPP = p2.x >= p4.x && p2.y >= p4.y;


  if(isPP && isPI ) {
    printf("o segundo retangulo esta contido no primeiro\n");
    return 0;
  }
  printf("o segundo retangulo nao esta contido no primeiro\n");

  return 0;
}

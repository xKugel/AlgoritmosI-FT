#include <stdio.h>
#include <math.h>

typedef struct corpo {
  float altura, peso;
  char nome[100];
} Corpo;

int main () {
  Corpo c;
  scanf("%f", &c.altura);
  scanf("%f", &c.peso);
  scanf("%s", c.nome);
  float imc = c.peso/(c.altura*c.altura);
  printf("\n%.3f\n", imc);

  return 0;
}

#include <stdio.h>
#define PI 3.14159

// Professor, dsclp se você sempre leu meus códigos
// e eu não deixei comentários pq achei q só usava o
// a Susy para corrigir ;-;
float volume_esfera (float raio);

float elevate (float num, int time);

float elevate (float num, int time) {
  float orig = num;
  for (int i = time; i > 1; i--) {
    num*=orig;
  }
  return num;
}

float volume_esfera (float raio) {
  return (4*PI*elevate(raio,3))/3;
}

int main () {
  float r;
  scanf("%f", &r);
  printf("%.2f\n", volume_esfera(r));
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

float elevate (float num, int time);
float elevate (float num, int time) {
  float orig = num;
  for (int i = time; i > 1; i--) {
    num*=orig;
  }
  return num;
}

int main () {
  int grauPoli;
  scanf("%i", &grauPoli);
  float* v;
  v = (float *) malloc((grauPoli+1)*sizeof(float));
  for(int i = grauPoli; i>=0; i--){
   scanf("%f", &v[i]);
  }
  float valor;
  float vAtual = 0;
  scanf("%f", &valor);
  for(int inte = 0; inte < grauPoli; inte++){
    vAtual += elevate(valor, grauPoli-inte)*v[inte];
  }
  vAtual += v[grauPoli];
  free(v);
  printf("%.2f\n",vAtual);

  return 0;
}

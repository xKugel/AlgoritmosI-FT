#include <stdio.h>
int n;
void procedimento (int vetor[]);

void procedimento (int vetor[]) {
  int maior, menor;
  for(int i = 0; i < n; i++) {
    if (i == 0) {
      maior = vetor[i];
      menor = maior;
    }
    maior = maior > vetor[i] ? maior : vetor[i];
    menor = menor < vetor[i] ? menor : vetor[i];
  }
  printf("maior valor: %i\n", maior);
  printf("menor valor: %i\n", menor);
};

int main () {
  scanf("%i", &n);
  int vt[n];
  for (int i = 0; i < n; i++) {
    int value;
    scanf("%i", &value);
    vt[i] =  value;
  }
  procedimento(vt);
  return 0;
};

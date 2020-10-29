#include <stdio.h>

int main() {
  int p1, p2, t;
  printf("Digite a nota da P1, P2 e do Trabalho do Aluno\n");
  printf("Primeira Prova: ");
  scanf("%d", &p1);
  printf("\nSegunda Prova: ");
  scanf("%d", &p2);
  printf("\nTrabalho: ");
  scanf("%d", &t);
  printf("\nSua Média Final é %d!\n", (p1+p2+t)/3);
  return 0;
}

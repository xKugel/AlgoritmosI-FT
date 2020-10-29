#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct aluno {
  char nome[100];
  int ra;
  float notaP1, notaP2;
};

char scaneiaESeta(struct aluno *a);
void processaEExibe(struct aluno *a, char overFrowxD);

char scaneiaESeta(struct aluno *a){
  fgets(a->nome, 100, stdin);
  char overFrowxD;
  // Aqui eu vejo se foi inputado um '\n', se for eu troco ele por um '\0', basicamente
  // troco uma quebra de linha, pela finalização dela.
  if ((strlen(a->nome) > 0) && (a->nome[strlen (a->nome) - 1] == '\n')) {
    a->nome[strlen (a->nome) - 1] = '\0';
    //PROFESSOR DO CEU EHAUEHAUEHU O SENHOR É SENSACIONAL HEAUHEUAHEUAEH OBG!! COM O LENGTH FULL ELE DA STACKOVER FLOW
    // INPUTA PRA FORA, ENTÂO EU LEIO ESSE INPUT E DPS RETORNO ELE E Q VIDA SEGUE NORMAL EHAUEHAUEHU SENSACIONAL!!!
  } else if (a->nome[strlen(a->nome)] == 0) {
    overFrowxD = getchar();
    char valid = getchar();
    while(valid != 10){
      valid = getchar();
    }
  }
  scanf("%i", &a->ra);
  scanf("%f", &a->notaP1);
  scanf("%f", &a->notaP2);
  return overFrowxD;
}

void processaEExibe(struct aluno *a, char overFrowxD) {
  // A esse nivel eu perdi o controle da minha vida, e to programando orientado à Mágica.
  if (overFrowxD != 0) {
    printf("%i\t%s%c\t%.2f\n", a->ra,a->nome, overFrowxD, (a->notaP1+a->notaP2)/2 );
  } else {
    printf("%i\t%s\t%.2f\n", a->ra,a->nome, (a->notaP1+a->notaP2)/2 );
  }
}

int main() {
 int x;
 scanf("%i", &x);
 struct aluno* alunos;
 alunos = (struct aluno*) malloc(x*sizeof(struct aluno));
 char overFrowxD = 0;
 for(int i = 0; i < x; i++) {
  getchar();
  overFrowxD = scaneiaESeta(&alunos[i]);
 }
 for(int i = 0; i < x; i++) {
  processaEExibe(&alunos[i], overFrowxD);
 }
 free(alunos);
 return 0;
}

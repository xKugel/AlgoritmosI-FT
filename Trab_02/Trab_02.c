#include  <stdio.h>
// Defino as respresentações da Tabela ASCII para cada alternativa.
#define A 65
#define B 66
#define C 67
#define D 68
#define E 69
#define NA 42
// Inicializo globalmente as váriaveis de entrada.
int a, b, c, d, e;

// Defino novos métodos para depois escreve-los.
int isBlack(int value, int letter);
int getAwnser(int a, int b, int c, int d, int e);
void readAwnsers();

/***
*  Método que verifica se o valor respectivo é preto ou não.
*
*  Pametros
*    int value => Valor que eu verifico a tonalidade de preto.
*    int letter => Letra da alternativa que está sendo verificada.
*
*   Retorno => O valor da Tabela ASCII da alternativa se estiver marcada, se não zero.
*
*/
int isBlack(int value, int letter) {
  return value >= 0 && value <= 127 ? letter : 0;
}

/***
* Método que soma todos valores das alternativas marcadas e não marcadas.
*
*  Pametros
*    int a => Valor da alternativa a à ser testada.
*    int b => Valor da alternativa b à ser testada.
*    int c => Valor da alternativa c à ser testada.
*    int d => Valor da alternativa d à ser testada.
*    int e => Valor da alternativa e à ser testada.
*
*   Retorno => soma de todos valores das alterativas.
*/
int getAwnser(int a, int b, int c, int d, int e) {
  return isBlack(a, A) + isBlack(b, B) + isBlack(c, C) + isBlack(d, D) + isBlack(e, E);
}

/***
* Método que lê a entrada das alterativas marcadas, processa elas
* e verifica se o valor da soma é uma única alternativa válida,
* caso seja exibe a alterativa marcada, caso não, exibe Asterico.
*/
void readAwnsers() {
  int awnser;
  scanf("%i %i %i %i %i", &a, &b, &c, &d, &e);
  awnser = getAwnser(a, b, c, d, e);
  if(awnser > 69 || awnser < 65) {
    awnser = NA;
  }
  printf("%c\n", awnser);
}

int main () {
  int perPage;
  scanf("%i", &perPage);
  // Leio a quantidade de questões por página enquanto elas forem maiores que zero.
  while (perPage > 0) {
    // Testo se quantidade é aceitavel, se sim, leio as respostas e exibo as assinaladas.
    if (0 < perPage && perPage <= 20) {
      for(int i = 0; i < perPage; i++) {
        readAwnsers();
      }
    }
    // Se não, aviso que não é válida, e Finalizo Programa.
    else {
      printf("Numero de questoes fora dos limites permitidos!\n");
      return 0;
    }
    scanf("%i", &perPage);
  }
  // Finalizo o programa.
  return 0;
}

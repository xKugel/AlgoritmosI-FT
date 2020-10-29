#include <stdio.h>
void procedimento (int a, int b, int c, int d, char op);
void procedimento (int a, int b, int c, int d, char op){
  //Professor, tive um dia longo, perdoa o a falta de esmero.
  if (op == '+') {
    printf("%i + %ii\n", a+c, b+d);
  } else {
    printf("%i + %ii\n", (a*c) -(b*d), (a*d) + (b*c));
  }
}

int main () {
  int a,b, c, d;
  char op;
  scanf("%i %i %c %i %i",&a, &b, &op,&c, &d );
  procedimento(a, b, c, d, op);
  return 0;
}

#include <stdio.h>
int main () {
  char input = getchar();


    if(input == 'A')
    printf("Opcao A.\n");

    if(input == 'B')
    printf("Opcao B.\n");

    if(input == 'C')
    printf("Opcao C.\n");

    if (input != 'A' && input != 'B' &&input != 'C')
     printf("OpcaoInvalida.\n");
  return 0;
}

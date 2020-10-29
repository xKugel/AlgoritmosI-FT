#include <stdio.h>

int main (){
  char operator;
  float firstFloat, secodFloat, result;
  scanf("%f%c%f", &firstFloat, &operator, &secodFloat);
  switch(operator) {
    case '+':
    result = firstFloat + secodFloat;
    break;
    case '-':
    result = firstFloat - secodFloat;
    break;
    case '/':
    result = firstFloat / secodFloat;
    break;
    case '*':
    result = firstFloat * secodFloat;
    break;
    default:
    printf("Operador invalido\n");
    return 0;
  }
  printf("%.3f%c%.3f=%.3f\n", firstFloat, operator, secodFloat, result);
  return 0;
}

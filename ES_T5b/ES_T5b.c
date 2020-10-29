#include <stdio.h>
#define MAX 100;
float fill(float array[], int index);
float attachMultiplyAndSumValues(float array[], float values[], int index);

int main() {
  int index = 10;
  int ftArray[index], scArray[index];

  fill(ftArray, index);
  fill(scArray, index);

  printf("o lucro foi de %.3f e a quantidade de produtos vendidos foi de %.0f\n",totValues, totItens);
  return 0;
}


float attachAndSumItens(float array[], int index) {
  float tot = 0;
  for(int i = 0; i < index; i++) {
    scanf("%f", &array[i]);
    tot += array[i];
  }
  return tot;
}

float attachMultiplyAndSumValues(float array[], float values[], int index){
  float tot = 0;
  for(int i = 0; i < index; i++) {
    scanf("%f", &values[i]);
    tot += values[i]*array[i];
  }
  return tot;
}

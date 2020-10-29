#include <stdio.h>
int in(float array[], float checkValue, int indexLength);

int main () {
  int index = 20;
  float vet[index], input;
  for(int i = 0; i < index; i++) {
    scanf("%f", &vet[i]);
  }
  scanf("%f", &input);
  while(input >= 0) {
    in(vet, input, index);
    scanf("%f", &input);
  }
  return 0;
}

int in(float array[], float checkValue, int indexLength) {
  for (int i = 0; i < indexLength; i++) {
    if(array[i] == checkValue) {
      printf("existe\n");
      return 1;
    }
  }
  printf("nao existe\n");
  return 0;
}

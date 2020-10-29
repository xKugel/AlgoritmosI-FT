#include <stdio.h>
#define MAX 200;

int fill(int array[], int index);
int concatEarch(int arr[], int array[], int index);

int main() {
  int index = 10, fsArray[index], scArray[index];

  fill(fsArray, index);
  fill(scArray, index);
  concatEarch(fsArray, scArray, index);
  return 0;
}


int fill(int array[], int index) {
  for(int i = 0; i < index; i++) {
    scanf("%i", &array[i]);
  }
  return 0;
}

int concatEarch(int arr[], int array[], int index){
  for(int i = 0; i < index; i++) {
    printf("%i|%i|", arr[i], array[i] );
  }
  printf("\n");
  return 0;
}

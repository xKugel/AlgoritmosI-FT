#include <stdio.h>

int a[10], b[10];
void procedimento(int vetora[], int vetorb[]);
void procedimento(int vetora[], int vetorb[]) {
  for (int i = 0; i< 10; i++) {
    vetorb[i] = vetora[i]*vetora[i]*vetora[i];
  };
};

int main () {
  int value;
  for (int i = 0; i <10; i++) {
    scanf("%i", &value);
    a[i] = value;
  };
  procedimento(a, b);
  for (int index = 0; index < 10; index++) {
    printf("%i\n", b[index]);
  }
  return 0;
}

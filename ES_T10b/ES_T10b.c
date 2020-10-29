#include <stdio.h>
#include <stdlib.h>


int main () {
  int x, y;
  scanf("%i %i", &x, &y);
  int** m;
  m = (int**) malloc(x*sizeof(int*));
  for (int alocM = 0; alocM < x; alocM++) {
    m[alocM] = (int*) malloc(y*sizeof(int));
  }
  for (int xI = 0; xI < x; xI++) {
    for (int yI = 0; yI < y; yI++) {
      scanf("%i", &m[xI][yI]);
    }
  }
  if (x == y) {
    int valid = 0;
    for (int xII = 0; xII < x; xII++) {
      for (int yII = 0; yII < y; yII++) {
        valid += m[xII][yII] == m[yII][xII] ? 0 : 1;
      }
    }
    if (valid != 0) {
      printf("Nao eh simetrica\n");
    } else {
      printf("Eh simetrica\n");
    }
    return 0;
  } else {
    printf("Nao eh simetrica\n");
  }
  return 0;
}

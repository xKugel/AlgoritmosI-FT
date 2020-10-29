#include <stdio.h>


int main () {
  int num_lim, num_col;
  scanf("%i %i", &num_lim, &num_col);
  int m[num_lim][num_col];
  for(int i = num_lim - 1 ; i >= 0; i--){
    for(int r = num_col - 1; r >= 0; r--){
      int input;
      scanf("%i", &input);
      m[i][r] = input;
    }
  }
  for(int i2 = num_col - 1; i2>= 0; i2--){
    for(int r2 = num_lim - 1; r2 >= 0; r2--){
      if ((r2 == 0 && i2 != 0) || (r2 == 0 && i2 == 0)) {
        printf("%i\n", m[r2][i2]);
      } else if (r2 == i2) {
        printf("%i ", m[i2][r2]);
      } else {
        printf("%i ", m[r2][i2]);
      }
    }
  }
  return 0;
}

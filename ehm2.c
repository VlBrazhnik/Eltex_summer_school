#include "stdio.h"

int main(){

  int rows = 3;
  int cols = 3;
  int count = 0;

  int arr[rows][cols];

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++) {

      count += 1;
      arr[i][j] = count;
      printf("%5d", arr[i][j]);
    }
      printf("\n");
  }

  return 0;
}

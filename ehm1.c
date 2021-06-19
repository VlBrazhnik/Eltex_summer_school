#include "stdio.h"
#include "stdlib.h"

// 1. Вывести квадратную матрицу по заданному N

int main()
{

int rows, cols, count;

rows = 3;
cols = 3;
count = 0;

int *arrayl = (int*)malloc(rows * cols * sizeof(int));

for (int i = 0; i < rows; i++)
{

    for (int j = 0; j < cols; j++)
    {

        count += 1;

        printf("%5d ",count);
    }
    printf("\n");
}

void free(void *arrayl);

  return 0;
}

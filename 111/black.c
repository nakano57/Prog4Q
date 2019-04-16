#include <stdio.h>
#include <stdlib.h>

void fillimage(unsigned char **img, unsigned char **cut_img, int *X_SIZE, int *Y_SIZE, int cut_x, int cut_y, int st_x, int st_y)
{
  int x, y;

  if ((cut_x + st_x) > *X_SIZE || (cut_y + st_y) > *Y_SIZE)
  {
    printf("サイズオーバーです\n");
  }

  for (y = 0; y < cut_y; y++)
  {
    for (x = 0; x < cut_x; x++)
    {
      img[y + st_y][x + st_x] = '0';
    }
  }
}

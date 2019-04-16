#include <stdio.h>
#include <stdlib.h>

// 180度回転
void rotation(unsigned char **img, int *X_SIZE, int *Y_SIZE)
{
    unsigned char tmp;
    int x, y;
    int is_upper;
    for (y = 0; y < *Y_SIZE; y++)
    {
        is_upper = y < *Y_SIZE / 2;
        for (x = 0; x < y + is_upper; x++)
        {
            tmp = img[*Y_SIZE - y - 1][*X_SIZE - x - 1];
            img[*Y_SIZE - y - 1][*X_SIZE - x - 1] = img[y][x];
            img[y][x] = tmp;
        }
    }
    return;
}

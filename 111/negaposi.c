#include <stdio.h>
#include <stdlib.h>

// ネガポジ反転
void negative_positive_reversal(unsigned char **img, int *GRAD, int *X_SIZE, int *Y_SIZE)
{
    int x, y;
    for (y = 0; y < *Y_SIZE; y++)
    {
        for (x = 0; x < *X_SIZE; x++)
        {
            img[y][x] = *GRAD - img[y][x];
        }
    }
    return;
}

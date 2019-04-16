#include <stdio.h>
#include <stdlib.h>

// 書き込み
void write_pgm(char *filename, unsigned char **img, int *GRAD, int *X_SIZE, int *Y_SIZE)
{
    FILE *ofp;
    int y;

    if ((ofp = fopen(filename, "wb")) == NULL)
    {
        fprintf(stderr, "File cannot be opened.\n");
        exit(EXIT_FAILURE);
    }

    // ヘッダを書き込み
    fprintf(ofp, "P5\n");
    // 画像サイズと階調を書き込み
    fprintf(ofp, "%d %d\n%d\n", *X_SIZE, *Y_SIZE, *GRAD);

    // バイナリデータを書き込み
    for (y = 0; y < *Y_SIZE; y++)
    {
        fwrite(img[y], sizeof(unsigned char), *X_SIZE, ofp);
    }
    fclose(ofp);
    return;
}

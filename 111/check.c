#include <stdio.h>
#include <stdlib.h>

// 読み込み
void check_pgm(char *filename, int *x_size, int *y_size, int *grad)
{
    FILE *ifp;
    char format[2];
    int y;

    // 前回の応用ですが，stderrはエラーメッセージ用のストリームです．
    if ((ifp = fopen(filename, "rb")) == NULL)
    {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    // ヘッダの読み込みと確認
    // fscanfは代入された入力項目の個数が返るので，足りなければエラー
    if (fscanf(ifp, "%c%c", format, format + 1) != 2)
    {
        fprintf(stderr, "Un-readable file type.\n");
        exit(EXIT_FAILURE);
    }
    if (format[0] != 'P' || format[1] != '5')
    {
        fprintf(stderr, "Un-readable file type.\n");
        exit(EXIT_FAILURE);
    }
    // 画像サイズの読み込みと確認
    if (fscanf(ifp, "%d %d\n", x_size, y_size) != 2)
    {
        fprintf(stderr, "File may be broken (%d-%d).\n", *x_size, *y_size);
        exit(EXIT_FAILURE);
    }

    // 階調の読み込みと確認
    if (fscanf(ifp, "%d\n", grad) != 1)
    {
        fprintf(stderr, "File may be broken (%d).\n", *grad);
        exit(EXIT_FAILURE);
    }

    fclose(ifp);
    return;
}

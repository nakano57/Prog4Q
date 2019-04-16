#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//unsigned char img[Y_SIZE][X_SIZE];
//int GRAD = 255;

extern void read_pgm(char *filename, unsigned char **img);
extern void check_pgm(char *filename, int *x_size, int *y_size, int *grad);
extern void write_pgm(char *filename, unsigned char **img, int *GRAD, int *X_SIZE, int *Y_SIZE);
extern void negative_positive_reversal(unsigned char **img, int *GRAD, int *X_SIZE, int *Y_SIZE);
extern void rotation(unsigned char **img, int *X_SIZE, int *Y_SIZE);
extern void cutimage(unsigned char **img, unsigned char **cut_img, int *X_SIZE, int *Y_SIZE, int cut_x, int cut_y, int st_x, int st_y);
void fillimage(unsigned char **img, unsigned char **cut_img, int *X_SIZE, int *Y_SIZE, int cut_x, int cut_y, int st_x, int st_y);

int main(int argc, char const *argv[])
{
    int *x, *y, *grad;
    int x_size, y_size, i, gd;
    unsigned char **img;
    unsigned char **cut_img;
    char *filename;
    char *savename;

    const char *pcut_x, *pcut_y, *pst_x, *pst_y;
    int cut_x = 1, cut_y = 1, st_x, st_y;

    filename = (char *)malloc(sizeof(char *) * 256);
    savename = (char *)malloc(sizeof(char *) * 256);

    x = &x_size;
    y = &y_size;
    grad = &gd;

    filename = (char *)argv[2];
    savename = (char *)argv[3];

    if (argc == 8)
    {

        pst_x = argv[4];
        pst_y = argv[5];
        pcut_x = argv[6];
        pcut_y = argv[7];

        st_x = strtol(pst_x, NULL, 10);
        st_y = strtol(pst_y, NULL, 10);
        cut_x = strtol(pcut_x, NULL, 10);
        cut_y = strtol(pcut_y, NULL, 10);
    }

    check_pgm(filename, x, y, grad);

    img = (unsigned char **)malloc(sizeof(unsigned char *) * *y);

    for (i = 0; i < *y; i++)
    {
        img[i] = (unsigned char *)malloc(sizeof(unsigned char) * *x);
    }

    cut_img = (unsigned char **)malloc(sizeof(unsigned char *) * cut_y);

    for (i = 0; i < *y; i++)
    {
        cut_img[i] = (unsigned char *)malloc(sizeof(unsigned char) * cut_x);
    }

    read_pgm(filename, img);

    if (!strcmp(argv[1], "rotation"))
    {
        rotation(img, x, y);
        write_pgm(savename, img, grad, x, y);
    }
    else if (!strcmp(argv[1], "negaposi"))
    {
        negative_positive_reversal(img, grad, x, y);
        write_pgm(savename, img, grad, x, y);
    }
    else if (!strcmp(argv[1], "cut"))
    {
        cutimage(img, cut_img, x, y, cut_x, cut_y, st_x, st_y);
        write_pgm(savename, cut_img, grad, x, y);
    }
    else if (!strcmp(argv[1], "fill"))
    {
        fillimage(img, cut_img, x, y, cut_x, cut_y, st_x, st_y);
        write_pgm(savename, img, grad, x, y);
    }

    return 0;
}

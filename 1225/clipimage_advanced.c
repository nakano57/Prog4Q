#include <stdio.h>
#include <stdlib.h>

void check_pgm(const char *filename, int *x_size, int *y_size)
{
  FILE *ifp;
  char format[2];
  int grad;

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
  if (fscanf(ifp, "%d %d", x_size, y_size) != 2)
  {
    fprintf(stderr, "File may be broken (%d-%d).\n", *x_size, *y_size);
    exit(EXIT_FAILURE);
  }

  // 階調の読み込みと確認
  if (fscanf(ifp, "%d", &grad) != 1)
  {
    fprintf(stderr, "File may be broken (%d).\n", grad);
    exit(EXIT_FAILURE);
  }
  if (grad != 255)
  {
    fprintf(stderr, "Illegal grad %d.\n", grad);
    exit(EXIT_FAILURE);
  }

  fclose(ifp);
  return;
}

void read_pgm(const char *filename, unsigned char **img, int *x_size, int *y_size)
{
  // バイナリデータの読み込み
  FILE *ifp;
  ifp = fopen(filename, "rb");
  char temp[2];
  int i = 0;

  //Streamを早送り
  fscanf(ifp, "%c%c", temp, temp + 1);
  fscanf(ifp, "%d %d", &i, &i);
  fscanf(ifp, "%d", &i);
  fscanf(ifp, "%d", &i);

  for (i = 0; i < *y_size; i++)
  {
    fread(img[i], sizeof(unsigned char), *x_size, ifp);
  }

  fclose(ifp);
  return;
}

void write_pgm(const char *filename, unsigned char **cimg, int *x_size, int *y_size,int *height, int *width)
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
  fprintf(ofp, "%d %d\n255\n",*width,*height);

  // バイナリデータを書き込み
  for (y = 0; y < *height; y++)
  {
    fwrite(cimg[y], sizeof(unsigned char), *width, ofp);
  }
  fclose(ofp);
  return;
}

void cutimage(unsigned char **img, unsigned char **cimg, int *x_size, int *y_size, int *height,int *width,int *x_start,int *y_start)
{
  int x, y;

  for (y = 0; y < *height; y++)
  {
    for (x = 0; x < *width; x++)
    {
      cimg[y][x] = img[y + *y_start][x + *x_start];
    }
  }
  return;
}

int main(int argc, char const *argv[])
{
  FILE *fp;
  int *x_size;
  int *x_start;
  int *y_size;
  int *y_start;
  int *width;
  int *height;
  char *sutax,*sutay,*takasa,*yoko;
  int x, y,pxs,pys,pwi,phe;
  int i;
  unsigned char **img;
  unsigned char **cimg;

  if (argc != 7)
  {
    printf("ERROR!\n");
    printf("usage: clipimage_advenced [File Path] [x start] [y_start] [width] [height] [Save Path]\n");
    printf("For example \"./clipimage_advanced lena.pgm 200 200 150 150 lena_clipped.pgm\"\n");
    return 1;
  }

  x_size = &x;
  y_size = &y;
  x_start = &pxs;
  y_start = &pys;
  width = &pwi;
  height = &phe;

  sutax = (char *)malloc(sizeof(argv[2]));
  sutay = (char *)malloc(sizeof(argv[3]));
  yoko = (char *)malloc(sizeof(argv[4]));
  takasa = (char *)malloc(sizeof(argv[5]));

  sutax = (char *)argv[2];
  sutay = (char *)argv[3];
  yoko = (char *)argv[4];
  takasa = (char *)argv[5];

  pxs = strtol(sutax, NULL, 10);
  pys = strtol(sutay, NULL, 10);
  pwi = strtol(yoko, NULL, 10);
  phe = strtol(takasa, NULL, 10);

  fp = fopen(argv[1], "rb");

  cimg = (unsigned char **)malloc(sizeof(unsigned char *) * (*height));
  for (i = 0; i < (*height); i++)
  {
    cimg[i] = (unsigned char *)malloc(sizeof(unsigned char) * (*width));
  }

  check_pgm(argv[1], x_size, y_size);

  img = (unsigned char **)malloc(sizeof(unsigned char *) * y);
  for (i = 0; i < y; i++)
  {
    img[i] = (unsigned char *)malloc(sizeof(unsigned char) * x);
  }

  read_pgm(argv[1], img, x_size, y_size);

  if(((*x_start)+(*width)) > *x_size || ((*y_start)+(*height))>*y_size){
    printf("too small to cut imgae\n");
    return 1;
  }

  cutimage(img, cimg, x_size, y_size,height,width,x_start,y_start);

  write_pgm(argv[6], cimg, x_size, y_size,height,width);

  fclose(fp);

  return 0;
}
//http://www.ai.cs.kobe-u.ac.jp/~enshu/doku.php?id=enshu4:tasks


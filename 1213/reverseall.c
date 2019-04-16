
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
  FILE *fp;
  FILE *fp2;
  char **alice;
  int nline = 0, i = 0, j = 0;
  char tmp;
  int *nchars;

  fp = fopen("alice.txt", "r");

  if (fp == NULL)
  {
    printf("File not found.\n");
  }
  else
  {

    while ((tmp = (char)fgetc(fp)) != EOF)
    {
      if (tmp == '\n')
      {
        nline++;
      }
    }

    alice = malloc(sizeof(int *) * nline);
    nchars = malloc(sizeof(int *) * nline);

    rewind(fp);

    while ((tmp = fgetc(fp)) != EOF)
    {
      nchars[j]++;
      if (tmp == '\n')
      {
        nchars[j]++;
        alice[j] = (char *)malloc(sizeof(char) * nchars[j]);
        j++;
      }
    }

    rewind(fp);

    for (i = 0; i < nline; i++)
    {
      fgets(alice[i], nchars[i], fp);

      if (ferror(fp) != 0)
      {
        printf("ファイルエラーが発生しました\n");

        clearerr(fp);
      }
    }
  }

  fp2 = fopen("alice_reverseall.txt", "w");

  if (fp2 == NULL)
  {
    printf("File cannot be opened.\n");
  }
  else
  {
    for (i = nline; i >= 0; i--)
    {

      for (j = (nchars[i] - 1); j >= 0; j--)
      {
        if (alice[i][j] != '\n' && alice[i][j] != '\0')
        {
          fputc(alice[i][j], fp2);
        }
      }
      if (i != nline)
      {
        fputc('\n', fp2);
      }
    }
    fclose(fp);
  }

  return 0;
}

#include "get_next_line.h"

int main(void)
{
  int   i;
  int   fd1;
  int   fd2;
  char  *line;

  i = 0;
  fd1 = open("tests/text1.txt", O_RDONLY);
  fd2 = open("tests/text2.txt", O_RDONLY);
  while (1)
  {
    if (i % 2 == 0)
      line = get_next_line(fd1);
    else
      line = get_next_line(fd2);
    if (line == NULL)
      break ;
    printf("%d: %s", i, line);
    free(line);
    i++;
  }
  return (0);
}

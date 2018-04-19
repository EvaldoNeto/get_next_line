#include "./libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int get_next_line(const int fd, char **line)
{
  char *buff;
  ssize_t n;
 
  buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
  n = read(fd, buff, BUFF_SIZE);
  ft_putnbr(n);
  ft_putchar('\t');
  *line = buff;
  return (0);
}

int main()
{
  char **line;
  int fd;

  line = (char **)malloc(sizeof(char *));
  ft_putnbr(BUFF_SIZE);
  ft_putchar('\n');
  fd = open("tests/in_the_name", O_RDONLY);
  get_next_line(fd, line);
  ft_putstr(*line);
  ft_putchar('\n');
  
  return (0);
}

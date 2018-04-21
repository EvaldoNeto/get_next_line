#include "./libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int check_newline(char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

int leading_newline(char *str)
{
  int i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (i);
      i++;
    }
  return (-1);
}

int get_next_line(const int fd, char **line)
{
  static char *buff = NULL;
  int i;
  char *mopa;
  int n;

  n = BUFF_SIZE;
  i = 0;
  if (!buff)
    if (!(buff = (char *)ft_memalloc(sizeof(char *) * (BUFF_SIZE + 1))))
      return (-1);
  if (!(mopa = (char *)ft_memalloc(sizeof(char *) * (BUFF_SIZE + 1))))
      return (-1);
  if (!(*buff))
    n = read(fd, buff, BUFF_SIZE);
  if (!check_newline(buff))
    {
      *line = ft_strcpy(mopa, buff);
      n = read(fd, buff, BUFF_SIZE);
      while (!check_newline(buff))
	{
	  *line = ft_strjoin(*line, buff);
	  n = read(fd, buff, BUFF_SIZE);
	}
      i = leading_newline(buff);
      *line = ft_strjoin(*line, ft_strsub(buff, 0, i));
      ft_memmove(buff, buff + i + 1, ft_strlen(buff + i));
	  ft_putstr(":\t PORRA :");
	  free(mopa);
	  free(buff);
	  buff = NULL;
    }
  else
    {
      i = leading_newline(buff);
      *line = ft_strsub(buff, 0, i);
	  ft_putstr(":\t PORRA :");
      ft_memmove(buff, buff + i + 1, ft_strlen(buff + i));
    }
  /*if (buff[0] == '\0')
    {
      //ft_putstr("\nPORRA\n");
      free(buff);
      buff = NULL;
      }*/
  //free(mopa);
  return (n < BUFF_SIZE) ? (0) : (1);
}

int main()
{
  char **line;
  int fd;
  int n;
  int i;

  i = 0;
  n = 10;
  line = (char **)ft_memalloc(sizeof(char *));
  ft_putnbr(BUFF_SIZE);
  ft_putchar('\n');
  fd = open("tests/in_the_name", O_RDONLY);
  while (i < 40)
    {
      n = get_next_line(fd, line);
      ft_putnbr(n);
      ft_putstr(":\t");
      ft_putstr(*line);
      ft_putchar('\n');
      i++;
    }
  /*get_next_line(fd, line);
  ft_putstr(*line);
  ft_putchar('\n');
  get_next_line(fd, line);
  ft_putstr(*line);
  ft_putchar('\n');
  get_next_line(fd, line);
  ft_putstr(*line);
  ft_putchar('\n');
  get_next_line(fd, line);
  ft_putstr(*line);
  ft_putchar('\n');*/
  
  return (0);
}

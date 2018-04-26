/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:23:38 by eneto             #+#    #+#             */
/*   Updated: 2018/04/26 23:20:36 by eneto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
  char **line;
  int fd1;
  int fd2;
  int fd3;
  int fd4;
  int i;
  int n;

  n = 0;
  i = 0;
  line = (char **)ft_memalloc(sizeof(char *));
  ft_putnbr(BUFF_SIZE);
  ft_putchar('\n');
  fd1 = open("tests/in_the_name", O_RDONLY);
  fd2 = open("tests/draft_browns", O_RDONLY);
  fd3 = open("tests/game_of_thrones", O_RDONLY);
  fd4 = open("tests/inorder_traversal", O_RDONLY);

  get_next_line(fd1, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd2, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd3, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd4, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  ft_putstr("\n\n");
  get_next_line(fd3, line);
  ft_putstr(*line);
  ft_putstr("\n\n");

  /*while (get_next_line(fd1, line))
    {
      ft_putnbr(ft_strlen(*line));
      ft_putstr(":\t");
      ft_putstr(*line);
      ft_putchar('\n');
      i++;
      n+= ft_strlen(*line);
    }
  ft_putnbr(ft_strlen(*line));
  ft_putstr(":\t");
  ft_putstr(*line);
  ft_putchar('\n');

  while (get_next_line(fd2, line))
    {
      ft_putnbr(ft_strlen(*line));
      ft_putstr(":\t");
      ft_putstr(*line);
      ft_putchar('\n');
      i++;
      n+= ft_strlen(*line);
    }
  ft_putnbr(ft_strlen(*line));
  ft_putstr(":\t");
  ft_putstr(*line);
  ft_putchar('\n');

  char temp[10];
  int k;

  k = read(-42, temp, 10);
  ft_putnbr(k);
  ft_putchar('\n');
  ft_putchar('\n');*/
  
  ft_putstr("--------------------------------------\n");
  ft_putnbr(fd1);
  ft_putnbr(fd2);
  ft_putnbr(fd3);
  ft_putnbr(fd4);
  get_next_line(-1, line);
  get_next_line(-1, line);
  
  return (0);
}

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

int cmpf(void *new, void *current)
{
  int x;
  int y;

  x = *(int *)new;
  y = *(int *)current;
  if (x < y)
    return (-1);
  else if (x > y)
    return (1);
  else
    return (0);
}

void print_data(void *data)
{
  int n;

  n = *(int *)data;
  ft_putnbr(n);
}

void test_cmpf()
{
  int n;
  int m;
  
  n = 1;
  m = 2;
  printf("%d\n", cmpf(&n, &m));
}

void dealloc(void *node)
{
  //t_btree *temp;

  free(node);
}

void test_btree()
{
  int n[9] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
  int i;
  t_btree *root;

  root = NULL;
  i = 0;
  while (i < 9)
    {
      btree_insert_avl(&root, &n[i], sizeof(int), &cmpf);
      i++;
    }
  btree_print(root, 0, &print_data);
  printf("\n");
}

void test_del_btree()
{
  int n[9] = {9, 5, 10, 0, 6, 11, -1, 1, 2};
  int i;
  t_btree *root;

  root = NULL;
  i = 0;
  while (i < 9)
    {
      btree_insert_avl(&root, &n[i], sizeof(int), &cmpf);
      i++;
    }
  i = 0;
  while (i < 9)
    {
      btree_deletenode_avl(&root, &n[i], &cmpf, &dealloc);
      i++;
    }
  //btree_deletenode_avl(&root, &n[2], &cmpf, &dealloc);
  btree_print(root, 0, &print_data);
}

void test2()
{
  char **line;
  int fd1;
  int fd2;
  int fd3;
  int fd4;
  /*int i;
    int n;

    n = 0;
    i = 0;*/
  line = (char **)ft_memalloc(sizeof(char *));
  ft_putnbr(BUFF_SIZE);
  ft_putchar('\n');
  fd1 = open("tests/in_the_name", O_RDONLY);
  fd2 = open("tests/draft_browns", O_RDONLY);
  fd3 = open("tests/game_of_thrones", O_RDONLY);
  fd4 = open("tests/inorder_traversal", O_RDONLY);

  get_next_line(fd1, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");
  get_next_line(fd2, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");
  get_next_line(fd3, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");
  get_next_line(fd4, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");
  get_next_line(fd1, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");
  get_next_line(fd3, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");

  while (get_next_line(fd1, line))
    {
      ft_putnbr(ft_strlen(*line));
      ft_putstr(":\t");
      ft_putstr(*line);
      free(*line);
      ft_putchar('\n');
    }
  ft_putstr(":\t");
  ft_putstr(*line);
  free(*line);
  ft_putchar('\n');

  /* while (get_next_line(fd2, line))
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
  int k = get_next_line(-1, line);
  ft_putstr("\n");
  ft_putstr("return value: ");
  ft_putnbr(k);
  ft_putstr("\n");
  get_next_line(-1, line);

  /*char *s1 = (char *)ft_memalloc(sizeof(char) * 10);  
    char *s2 = (char *)ft_memalloc(sizeof(char) * 11);
    ft_memmove(s1, "MOPA", sizeof(char)*5);
    ft_memmove(s2, "CAPIROTICA", sizeof(char)*11);
    ft_putendl(s1);
    ft_putendl(s2);
    char *str = ft_strjoin_free(s1, s2);
    ft_putendl(s1);
    ft_putendl(s2);
    ft_putendl(str);*/
  free(line);
}

int main()
{
  //test_btree();
  printf("---------------------------------------\n");
  test_del_btree();
  return (0);
}

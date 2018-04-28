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
  int n[12] = {9, 5, 10, 0, 6, 11, -1, 1, 2, -5, -3, 8};
  //int n[3] = {9, 5, 10};
  int i;
  t_btree *root;

  root = NULL;
  i = 0;
  while (i < 12)
    {
      btree_insert_avl(&root, &n[i], sizeof(int), &cmpf);
      i++;
    }
  i = 0;
  while (i < 9)
    {
      btree_deletenode_avl(&root, &n[i], &cmpf, &free);
      i++;
    }
  /*btree_deletenode_avl(&root, &n[2], &cmpf, &free);
  btree_deletenode_avl(&root, &n[5], &cmpf, &free);
  btree_deletenode_avl(&root, &n[0], &cmpf, &free);*/
  btree_print(root, 0, &print_data);
}

void test_1full_file()
{
  char **line;

  int fd1;
  line = (char **)ft_memalloc(sizeof(char*));
  fd1 = open("tests/in_the_name", O_RDONLY);

  while (get_next_line(fd1, line))
    {
      ft_putstr(*line);
      free(*line);
      ft_putchar('\n');
    }
  ft_putstr(*line);
  free(*line);
  ft_putchar('\n');
}

void test_1partial_file()
{
  char **line;
  int fd1;
  int i;
  
  line = (char **)ft_memalloc(sizeof(char*));
  fd1 = open("tests/in_the_name", O_RDONLY);
  i = 0;
  while (get_next_line(fd1, line) && i < 10)
    {
      ft_putstr(*line);
      free(*line);
      ft_putchar('\n');
      i++;
    }
  ft_putstr(*line);
  free(*line);
  ft_putchar('\n');
}

void test_no_file()
{
  int n;
  char **line;
  int fd;
  
  line = (char **)ft_memalloc(sizeof(char*));
  *line = ft_strnew(sizeof(char) * 100);
  printf("mopa: %s\n", *line);
  fd = open("tests/in_the_name", O_RDONLY);
  close(fd);
  n = get_next_line(fd, line);
  printf("file closed return value: %d\n", n);
  n = get_next_line(4, line);
  printf("no file return value: %d\nline:", n);
}

void test_2full_files_samefd()
{
  char **line;
  int fd1;
  
  line = (char **)ft_memalloc(sizeof(char*));
  fd1 = open("tests/draft_browns", O_RDONLY);
  printf("%d\n", fd1);
  while (get_next_line(fd1, line))
    {
      ft_putstr(*line);
      free(*line);
      ft_putchar('\n');
    }
  ft_putchar('\n');
  close(fd1);
  fd1 = open("tests/in_the_name", O_RDONLY);
  while (get_next_line(fd1, line))
    {
      ft_putstr(*line);
      free(*line);
      ft_putchar('\n');
    }
  ft_putchar('\n');
  printf("%d\n", fd1);
}

void test_2full_files_diffsfd()
{
  char **line;
  int fd1;
  int fd2;
  int n;
  
  line = (char **)ft_memalloc(sizeof(char*));
  fd1 = open("tests/draft_browns", O_RDONLY);
  printf("%d\n", fd1);
  while ((n = get_next_line(fd1, line)))
    {
      ft_putnbr(n);
      ft_putstr(": ");
      ft_putstr(*line);
      free(*line);
      ft_putchar('\n');
    }
  printf("%d\n", fd1);
  ft_putchar('\n');
  fd2 = open("tests/in_the_name", O_RDONLY);
  while ((n = get_next_line(fd2, line)))
    {
      ft_putnbr(n);
      ft_putstr(": ");
      ft_putstr(*line);
      free(*line);
      ft_putchar('\n');
    }
  free(*line);
  //ft_putchar('\n');
  //printf("%d\n", fd2);
  free(line);
  //close(fd1);
  //close(fd2);
}

void test_del_tree()
{
  char **line;
  int fd1;
  int fd2;
  
  line = (char **)ft_memalloc(sizeof(char*));
  fd1 = open("tests/draft_browns", O_RDONLY);
  while (get_next_line(fd1, line))
      free(*line);
  free(*line);
  printf("\nfile descriptor 1: %d\n", fd1);
  ft_putchar('\n');
  fd2 = open("tests/in_the_name", O_RDONLY);
  while (get_next_line(fd2, line))
      free(*line);
  free(*line);
  ft_putchar('\n');
  printf("\nfile descriptor 2: %d\n", fd2);
  free(line);
}

void test_memmove()
{
  char *str = ft_strdup("capiroto");

  ft_putstr(str);
  ft_putstr("\n" );
  ft_memmove(str, str + 4, ft_strlen(str + 4) + 1);
  ft_putstr(str);
  ft_putstr("\n" );
}

void test_multiple_files()
{
  char **line;
  int fd1;
  int fd2;
  int fd3;
  int fd4;

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
  ft_putchar('\n');
  get_next_line(fd1, line);
  ft_putstr(*line);
  free(*line);
  ft_putstr("\n\n");
  ft_putchar('\n');
  ft_putstr("--------------------------------------\n");
  ft_putnbr(fd1);
  ft_putnbr(fd2);
  ft_putnbr(fd3);
  ft_putnbr(fd4);
  free(line);
}

int main()
{
  //test_btree();
  //test_del_btree();
  //  test_1full_file();
  //  test_1partial_file();
  //test_2full_files_samefd();
  //test_memmove();
  //test_no_file();
  //test_2full_files_diffsfd();
  //test_multiple_files();
  //test_del_tree();
  
  return (0);
}

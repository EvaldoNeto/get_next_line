/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneto <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:23:38 by eneto             #+#    #+#             */
/*   Updated: 2018/05/03 13:26:27 by eneto            ###   ########.fr       */
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
  free(line);
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
  fd = open("tests/in_the_name", O_RDONLY);
  close(fd);
  n = get_next_line(fd, line);
  printf("file closed return value: %d\n", n);
  n = get_next_line(-1, line);
  printf("no file return value: %d\n", n);
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

void test_simple_string()
{
  char **line;
  
  int fd1;
  line = (char **)ft_memalloc(sizeof(char*));
  fd1 = open("tests/simple_string", O_RDONLY);

  int i = 0;
  while (get_next_line(fd1, line))
    {
      ft_putnbr(i);
      ft_putstr(" :");
      ft_putendl(*line);
      free(*line);
      i++;
    }
  free(line);
}

void test_stream()
{
  char *line;

  while (get_next_line(1, &line))
    ft_putendl(line);
  /*  write(0, "aaa\nbbb\nccc\nddd\n", 16);
  get_next_line(0, &line);
  ft_putendl(line);*/
}

void test_pipe()
{
  char 	*line;
  int		out;
  int		p[2];
  int		fd;
  int		ret;
  int count;

  count = 0;
  out = dup(1);
  pipe(p);

  fd = 1;
  dup2(p[1], fd);
  write(fd, "abcd\n", 5);
  write(fd, "efgh\n", 5);
  write(fd, "ijkl\n", 5);
  write(fd, "mnop\n", 5);
  write(fd, "qrst\n", 5);
  write(fd, "uvwx\n", 5);
  write(fd, "yzab\n", 5);
  close(p[1]);
  dup2(out, fd);
  get_next_line(p[0], &line);
  if (ft_strcmp(line, "abcd") == 0)
    count++;
  get_next_line(p[0], &line);
  if (ft_strcmp(line, "efgh") == 0)
    count++;
  get_next_line(p[0], &line);
  if (ft_strcmp(line, "ijkl") == 0)
    count++;
  get_next_line(p[0], &line);
  if (ft_strcmp(line, "mnop") == 0)
    count++;
  get_next_line(p[0], &line);
  if (ft_strcmp(line, "qrst") == 0)
    count++;
  get_next_line(p[0], &line);
  if (ft_strcmp(line, "uvwx") == 0)
    count++;
  get_next_line(p[0], &line);
  if (ft_strcmp(line, "yzab") == 0)
    count++;
  ret = get_next_line(p[0], &line);
  if (ret == 0 && count == 7)
    printf("test_pipe: [OK]!\n");
  else
    printf("test_pipe: [ERROR]! count: %d\n", count);
}

void test_simple_file()
{
  char 	*line;
  int		out;
  int		p[2];
  int		fd;
  int count;
  int ret;

  count = 0;
  fd = 1;
  out = dup(fd);
  pipe(p);

  dup2(p[1], fd);
  write(fd, "aaa\nbbb\nccc\nddd\n", 16);
  dup2(out, fd);
  close(p[1]);
  get_next_line(p[0], &line);
  if(ft_strcmp(line, "aaa") == 0)
    count++;
//  printf("%s\n", line);
  get_next_line(p[0], &line);
  if(ft_strcmp(line, "bbb") == 0)
    count++;
//  printf("%s\n", line);
  get_next_line(p[0], &line);
  if(ft_strcmp(line, "ccc") == 0)
    count++;
//  printf("%s\n", line);
  get_next_line(p[0], &line);
  if(ft_strcmp(line, "ddd") == 0)
    count++;
//  printf("%s\n", line);
  ret = get_next_line(p[0], &line);
  if (ret == 0 && count == 4)
    printf("test_simple_file: [OK]!\n");
  else
    printf("test_simple_file: [ERROR]! count: %d\n", count);
}

void test_2_lines()
{
  char 	*line;
  int		out;
  int		p[2];
  int		fd;
  int count;
  int ret;

  count = 0;
  out = dup(1);
  pipe(p);

  fd = 1;
  dup2(p[1], fd);
  write(fd, "abcdefgh\n", 9);
  write(fd, "ijklmnop\n", 9);
  close(p[1]);
  dup2(out, fd);
  get_next_line(p[0], &line);
  if(ft_strcmp(line, "abcdefgh") == 0)
    count++;
  get_next_line(p[0], &line);
  if(ft_strcmp(line, "ijklmnop") == 0)
    count++;
  ret =   get_next_line(p[0], &line);
  if (ret == 0 && count == 2)
    printf("07_test_2_lines: [OK]!\n");
  else
    printf("07_test_2_lines: [ERROR]! count: %d\n", count);
}

void test_multi_file()
{
  char	*line_fd0;
  int		p_fd0[2];
  int		fd0 = 0;
  int		out_fd0 = dup(fd0);

  char	*line_fd1;
  int		p_fd1[2];
  int		fd1 = 1;
  int		out_fd1 = dup(fd1);

  char	*line_fd2;
  int		p_fd2[2];
  int		fd2 = 2;
  int		out_fd2 = dup(fd2);

  char	*line_fd3;
  int		p_fd3[2];
  int		fd3 = 3;
  int		out_fd3 = dup(fd3);

//  printf("COMECOU\n");
  
  pipe(p_fd0);
  dup2(p_fd0[1], fd0);
  write(fd0, "aaa\nbbb\n", 8);
  close(p_fd0[1]);
  dup2(out_fd0, fd0);

  pipe(p_fd1);
  dup2(p_fd1[1], fd1);
  write(fd1, "111\n222\n", 8);
  close(p_fd1[1]);
  dup2(out_fd1, fd1);

  pipe(p_fd2);
  dup2(p_fd2[1], fd2);
  write(fd2, "www\nzzz\n", 8);
  close(p_fd2[1]);
  dup2(out_fd2, fd2);

  pipe(p_fd3);
  dup2(p_fd3[1], fd3);
  write(fd3, "888\n999\n", 8);
  close(p_fd3[1]);
  dup2(out_fd3, fd3);
  

  int count = 0;
  int m;
  
  m = get_next_line(p_fd0[0], &line_fd0);
  if(ft_strcmp(line_fd0, "aaa") == 0)
    count++;
  //  printf("aaa : %s\n fd0 ret: %d\n", line_fd0, m);
  
  m =  get_next_line(p_fd1[0], &line_fd1);
  if(ft_strcmp(line_fd1, "111") == 0)
    count++;
  //  printf("111 : %s\n fd1 ret: %d\n", line_fd1, m);
  
  m = get_next_line(p_fd2[0], &line_fd2);
  if(ft_strcmp(line_fd2, "www") == 0)
    count++;
  //  printf("www : %s\n fd2 ret: %d\n", line_fd2, m);
  
  m = get_next_line(p_fd3[0], &line_fd3);
  if(ft_strcmp(line_fd3, "888") == 0)
    count++;
  //  printf("888 : %s\n fd3 ret: %d\n", line_fd3, m);
  
  m = get_next_line(p_fd0[0], &line_fd0);
  if(ft_strcmp(line_fd0, "bbb") == 0)
    count++;
  //  printf("bbb : %s\n fd0 ret: %d\n", line_fd0, m);
  
  m = get_next_line(p_fd1[0], &line_fd1);
  if(ft_strcmp(line_fd1, "222") == 0)
    count++;
  //  printf("222 : %s\n fd1 ret: %d\n", line_fd1, m);
    
  m = get_next_line(p_fd2[0], &line_fd2);
  if(ft_strcmp(line_fd2, "zzz") == 0)
    count++;
  //  printf("zzz : %s\n fd2 ret: %d\n", line_fd2, m);

  m = get_next_line(p_fd3[0], &line_fd3);
  if(ft_strcmp(line_fd3, "999") == 0)
    count++;
  //  printf("999 : %s\n fd3 ret: %d\n", line_fd3, m);
  
  if (count == 8)
    printf("30_test_multi_files: [OK]!\n");
  else
    printf("30_test_multi_files: [ERROR]! count: %d\n", count);
  m++;
}

int main()
{
  //test_btree();
  //test_del_btree();
  //test_1full_file();
  //  test_1partial_file();
  //test_2full_files_samefd();
  //test_memmove();
  //test_no_file();
  //  test_2full_files_diffsfd();
  //test_del_tree();
  //  test_simple_string();
	/*test_stream();*/
	test_simple_file();
	test_pipe();
	test_2_lines();
	test_multi_file();
  //  test_multiple_files();
  return (0);
}

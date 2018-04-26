#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 20

typedef struct s_file
{
  char *buffer;
  int fd;
} t_file;

int get_next_line(const int fd, char **line);

#endif

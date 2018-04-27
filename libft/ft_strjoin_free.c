#include "libft.h"

char *ft_strjoin_free(char *s1, char *s2)
{
  char *str;

  if (!(str = ft_strjoin(s1, s2)))
    return (NULL);
  free(s1);
  free(s2);
  s1 = NULL;
  s2 = NULL;
  return (str);
}

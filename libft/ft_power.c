

unsigned int ft_power(int base, int n)
{
  unsigned int i;

  i = 1;
  while (n > 0)
    {
      i = i * base;
      n--;
    }
  return (i);
}

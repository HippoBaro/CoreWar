/*
** my_putnbr.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM/lib
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 16:07:08 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:15:01 2015 Hippolyte Barraud
*/

#include        "corewar.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(1);
}

void	my_putstr(char *s)
{
  int	i;

  i = -1;
  while (s[++i]);
  if (write(1, s, i) == -1)
    exit(1);
}

int	my_putnbr(int nb)
{
  my_putchar(nb < 0 && (nb *= -1) ? '-' : '\0');
  my_putchar(nb - (nb >= 10 ? my_putnbr(nb / 10) : 0) + 48);
  return (nb * 10);
}

int64_t         my_getnbr(char *s)
{
  int64_t       sign;
  int64_t    	nb;
  int           i;

  if (s == NULL)
    return (0);
  sign = 1;
  nb = 0;
  i = -1;
  while (s[++i] && (s[i] == '-' || s[i] == '+'))
    sign *= s[i] == '-' ? -1 : 1;
  i--;
  while (s[++i] >= '0' && s[i] <= '9')
    nb = nb * 10 - 48 + s[i];
  return (nb * sign);
}

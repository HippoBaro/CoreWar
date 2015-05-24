/*
** my_printf.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:03:41 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:03:42 2015 Hippolyte Barraud
*/

#include	<stdarg.h>
#include	"my.h"

void		my_printf(char *s, ...)
{
  va_list	ap;
  int		i;

  va_start(ap, s);
  i = -1;
  while (s[++i])
    {
      if (s[i] == '%' && s[i + 1] == 's' && ++i)
	my_putstr(va_arg(ap, char *));
      else if (s[i] == '%' && s[i + 1] == 'd' && ++i)
	my_putnbr(va_arg(ap, int));
      else
	my_putchar(s[i] == '%' && s[++i] == 'c' ? va_arg(ap, int) : s[i]);
    }
  va_end(ap);
}

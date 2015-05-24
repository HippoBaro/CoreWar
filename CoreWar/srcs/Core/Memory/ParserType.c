/*
** ParserType.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:06:06 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:06:20 2015 Hippolyte Barraud
*/
#include        "op.h"
#include        "corewar.h"

char	GetByteAt(char types[], unsigned char c)
{
  int	i;
  int	n;
  char	arg;
  char	d1;
  char	d2;

  i = 7;
  n = 0;
  arg = 0;
  while (i >= 0)
    {
      d1 = !!(c & (1 << i));
      i--;
      d2 = !!(c & (1 << i));
      types[n] = d1 * 2 + d2;
      if (types[n++] > 0)
        arg++;
      i--;
    }
  types[n] = '\0';
  return (arg);
}

static void	FillTypeArray_Helper(char c, char type[])
{
  if (c == STI)
    {
      if (type[1] != 1)
	type[1] = 4;
      if (type[2] != 1)
	type[2] = 4;
    }
  else if (c == LDI || c == LLDI)
    {
      type[0] = 4;
      type[1] = 4;
    }
}

void	FillTypeArray(char c, char type[])
{
  if (c == LD || c == LLD)
    type[1] = 1;
  else if (c == ST)
    type[0] = 1;
  else if (c == ZJMP)
    type[0] = 4;
  else if (c == ADD || c == SUB)
    {
      type[0] = 1;
      type[1] = 1;
      type[2] = 1;
    }
  else if (c == AND || c == OR || c == XOR)
    type[2] = 1;
  else
    FillTypeArray_Helper(c, type);
}

void	FillArgsForAction(char *memory, int *i, int arg[],
			  char nb, char type[])
{
  int	n;
  int	s;

  n = 0;
  while (nb > 0 && n < 4)
    {
      s = 0;
      if (type[n] == 1)
        s = REG_SIZE;
      else if (type[n] == 2)
        s = DIR_SIZE;
      else if (type[n] == 3 || type[n] == 4)
        s = IND_SIZE;
      if (s == 1)
	arg[n] = FillByteChar(memory, i);
      else if (s == 2)
	arg[n] = Fill8BitShort(memory, i, s);
      else if (s == 4)
	arg[n] = Fill8BitInt(memory, i, s);
      n++;
      nb--;
    }
  arg[n] = '\0';
}

/*
** asm-utils.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 15:57:23 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:50:04 2015 Hippolyte Barraud
*/

#include        "corewar.h"

void	fill_arg_type(t_cmd *line, int *i)
{
  int	j;
  int	type;

  (*i)++;
  line->bin[*i] = 0;
  j = -1;
  while (++j < MAX_ARGS_NUMBER)
    {
      if (line->arg.type[j] == T_IND || line->arg.type[j] == T_LAB)
        type = line->arg.type[j] == T_IND ? 3 : T_DIR;
      else
        type = line->arg.type[j];
      line->bin[*i] |= type << ((MAX_ARGS_NUMBER - 1 - j) * 2);
    }
}

void	fill_arg(t_cmd *line, int *i, int nb, int size)
{
  char	charn;
  short	shortn;
  void	*ptr;
  int	j;

  charn = (char) nb;
  shortn = (short) nb;
  if (size <= 2)
    ptr = size == 1 ? (void *) &charn : (void *) &shortn;
  else
    ptr = (void *) &nb;
  j = -1;
  while (++j < size)
    line->bin[++(*i)] = ((char *) ptr)[size - 1 - j];
}

int	get_arg_size(int code, int offset, int type)
{
  if (code == 9 || code == 0x0c || code == 0x0F)
    return (IND_SIZE);
  if (code == 0x02 && offset == 0 && type == T_LAB)
    return (DIR_SIZE);
  if (code == 0x0a && offset < 2 && type != T_REG)
    return (IND_SIZE);
  if (code == 0x0b && offset > 0 && type != T_REG)
    return (IND_SIZE);
  if (type == T_LAB || type == T_IND)
    return (IND_SIZE);
  if (type == T_DIR)
    return (DIR_SIZE);
  return (REG_SIZE);
}

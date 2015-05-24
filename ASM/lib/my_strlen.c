/*
** my_strlen.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM/lib
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 16:08:56 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:16:20 2015 Hippolyte Barraud
*/

#include        "corewar.h"

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

int	my_tablen(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i]);
  return (i);
}

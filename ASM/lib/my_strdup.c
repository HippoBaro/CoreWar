/*
** my_strdup.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM/lib
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 16:08:35 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:15:49 2015 Hippolyte Barraud
*/

#include        "corewar.h"

char	*my_strdup(char *s)
{
  int	len;
  char	*dest;

  len = 0;
  while (s[len])
    len++;
  dest = xmalloc(len + 1);
  dest[len] = '\0';
  while (--len >= 0)
    dest[len] = s[len];
  return (dest);
}

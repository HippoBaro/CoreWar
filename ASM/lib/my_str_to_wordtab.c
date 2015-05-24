/*
** my_str_to_wordtab.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM/lib
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 16:07:54 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:17:21 2015 Hippolyte Barraud
*/

#include        "corewar.h"

int	count_words(char *str)
{
  int	i;
  int	words;

  words = 0;
  i = -1;
  while (str[++i])
    {
      if (i == 0 || (!IS_SPACE(str[i]) && IS_SPACE(str[i - 1])))
        words++;
    }
  return (words);
}

int	get_word(char *str, char **dest)
{
  int	i;
  int	j;

  if ((*dest = malloc(my_strlen(str) + 1)) == NULL)
    exit(1);
  i = -1;
  j = -1;
  while (str[++i] && IS_SPACE(str[i]));
  i--;
  while (str[++i] && !IS_SPACE(str[i]))
    (*dest)[++j] = str[i];
  (*dest)[++j] = '\0';
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	size;
  int	i;
  int	j;

  if ((size = count_words(str)) == -1)
    return (NULL);
  if ((tab = malloc((size + 1) * sizeof(char *))) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  while (++i < size)
    j += get_word(str + j, &(tab[i]));
  tab[i] = NULL;
  return (tab);
}

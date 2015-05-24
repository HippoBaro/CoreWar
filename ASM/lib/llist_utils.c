/*
** llist_utils.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM/lib
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 16:06:44 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:14:24 2015 Hippolyte Barraud
*/

#include        "corewar.h"

int		list_add_char(t_char **end, char *str, int len)
{
  t_char        *elm;

  elm = malloc(sizeof(t_char));
  if (elm == NULL)
    exit(EXIT_FAILURE);
  elm->str = str;
  elm->to_free = str;
  elm->len = len;
  elm->next = NULL;
  if (*end != NULL)
    (*end)->next = elm;
  *end = elm;
  return (0);
}

int	list_add_node(t_cmd **begin, t_cmd **end, t_cmd *elm)
{
  elm->next = NULL;
  if (*begin == NULL)
    *begin = elm;
  else
    (*end)->next = elm;
  *end = elm;
  return (0);
}

int		list_replace_node(t_cmd **rmbegin, t_cmd **replace,
				  t_cmd *elm)
{
  t_cmd		*it;

  it = *rmbegin;
  while (it && it->next != elm)
    it = it->next;
  if (it && it->next == elm)
    it->next = elm->next;
  elm->next = *replace;
  *replace = elm;
  elm->arg.argv[0][my_strlen(elm->arg.argv[0]) - 1] = '\0';
  return (0);
}

/*
** llist_utils.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:03:32 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:03:33 2015 Hippolyte Barraud
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"my.h"

int		my_push_back(t_char **end, char *str, int len)
{
  t_char	*elm;

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

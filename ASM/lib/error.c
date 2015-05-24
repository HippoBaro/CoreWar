/*
** error.c for ASM in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Tue Mar 24 16:51:14 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:51:30 2015 Hippolyte Barraud
*/

#include        "corewar.h"

void     syntax_prompt(char *desc, char *line, int arg_num, bool isCritical)
{
  arg_num++;
  if (isCritical)
    my_putstr(RED "Error : " BLANK);
  else
    my_putstr(YELLOW "Warning : " BLANK);
  my_putstr(desc);
  if (arg_num != 0)
    {
      my_putstr(" for argument ");
      my_putnbr(arg_num);
    }
  my_putstr(" at line :\n\"");
  my_putstr(line);
  my_putstr("\"\n");
  if (isCritical)
    {
      my_putstr(RED "Compilation failed.\n" BLANK);
      exit(EXIT_FAILURE);
    }
}

static void	print_error(char *error, const bool isCritical)
{
  my_putstr(error);
  if (isCritical)
    exit(EXIT_FAILURE);
}

void	*xmalloc(const size_t size)
{
  void	*p;

  p = malloc(size);
  if (p == NULL)
    print_error("malloc error\n", TRUE);
  return (p);
}

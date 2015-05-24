/*
** utils.c for Corewar in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Apr 24 02:43:12 2015 Hippolyte Barraud
** Last update Fri Apr 24 02:44:00 2015 Hippolyte Barraud
*/

#include "corewar.h"

void	*xmalloc(const size_t size)
{
  void	*p;

  p = malloc(size);
  if (p == NULL)
    PrintError("A critical error occurred during memory allocation", TRUE);
  return (p);
}

void 	FatalError(int code)
{
  if (code)
    PrintError("Virtual machine has stoped. One champion has corrupted data.",
	       TRUE);
}

void 	PrintError(char *message, bool isCritical)
{
  if (isCritical)
    my_putstr(RED);
  else
    my_putstr(YELLOW);
  my_putstr(message);
  my_putstr(BLANK "\n");
  if (isCritical)
    exit(EXIT_FAILURE);
}

void	PrintMatchResult(t_vm *arena)
{
  if (arena->champs != NULL)
    my_printf("Player %d (%s) has won the game.", arena->champs->InstanceIndex,
	      arena->champs->Name);
  else
    my_putstr(arena->InstanceNameForLastAction);
  my_putstr("\n");
}

bool	CheckArgs(int *argv, int num)
{
  if (!REG_VALID(argv[num]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return (TRUE);
    }
  return (FALSE);
}

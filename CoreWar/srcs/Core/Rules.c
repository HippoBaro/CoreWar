/*
** Rules.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:05:49 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:05:50 2015 Hippolyte Barraud
*/

#include        "op.h"
#include        "corewar.h"

static void	SetDelayTab(int delayTab[])
{
  delayTab[0] = 10;
  delayTab[1] = 5;
  delayTab[2] = 5;
  delayTab[3] = 10;
  delayTab[4] = 10;
  delayTab[5] = 6;
  delayTab[6] = 6;
  delayTab[7] = 6;
  delayTab[8] = 20;
  delayTab[9] = 25;
  delayTab[10] = 25;
  delayTab[11] = 800;
  delayTab[12] = 10;
  delayTab[13] = 50;
  delayTab[14] = 1000;
  delayTab[15] = 2;
}

int	GetDelayForAction(char actionCode)
{
  int	delayTab[16];
  int	i;

  i = (int)actionCode;
  SetDelayTab(delayTab);
  if (actionCode >= 0 && actionCode < 16)
    return (delayTab[i]);
  return (FALSE);
}

int	GetTypeForAction(char actionCode)
{
  if (actionCode == LIVE || actionCode == ZJMP || actionCode == FORK
      || actionCode == LFORK)
    return (0);
  if (actionCode > 0 && actionCode <= 16)
    return (1);
  return (-1);
}

void	SetActionTab(ACTIONPTR, t_vm *arena)
{
  arena->CycleForTurn = 0;
  FunctionArray[0] = live;
  FunctionArray[1] = ld;
  FunctionArray[2] = st;
  FunctionArray[3] = add;
  FunctionArray[4] = sub;
  FunctionArray[5] = and;
  FunctionArray[6] = or;
  FunctionArray[7] = xor;
  FunctionArray[8] = zjmp;
  FunctionArray[9] = ldi;
  FunctionArray[10] = sti;
  FunctionArray[11] = my_fork;
  FunctionArray[12] = lld;
  FunctionArray[13] = lldi;
  FunctionArray[14] = lfork;
  FunctionArray[15] = aff;
}

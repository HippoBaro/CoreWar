/*
** Init.c for Corewar in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Apr 24 03:05:41 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:05:42 2015 Hippolyte Barraud
*/

#include        "op.h"
#include        "corewar.h"

int		InitChampions(t_vm *vm)
{
  t_instance	*tmp;

  vm->LiveCount = 0;
  tmp = vm->champs;
  while (tmp != NULL)
    {
      tmp->LastLive = 0;
      tmp->CurrentCycle = 0;
      tmp = tmp->next;
    }
  return (SUCCESS);
}

static int	GenerateInstanceUUID(int *t)
{
  int		ret;

  ret = t[0];
  ret++;
  while (ret == t[0] || ret == t[1] || ret == t[2] || ret == t[3])
    ret++;
  return (ret);
}

static void	InitInstance(int *UUIDs, t_instance *start, int *i, int *y)
{
  if (UUIDs[*i] == -1)
	UUIDs[*i] = GenerateInstanceUUID(UUIDs);
  start->InstanceIndex = *i + 1;
  start->InstanceNumber = UUIDs[*i];
  start->LiveCount = start->LastLive = start->Delay = 0;
  start->Parent = *y = -1;
  while (++*y < REG_NUMBER)
	start->Args[*y] = 0;
  start->Args[1] = start->InstanceNumber;
}

t_instance	*CreateInstances(int *UUIDs, char **argv)
{
  int		i;
  int		y;
  t_instance 	*start;
  t_instance	*current;
  t_instance	*last;

  i = 0;
  last = current = start = xmalloc(sizeof(t_instance));
  while ((start->Name = GetInstanceName(argv, i)) != NULL)
	{
	  InitInstance(UUIDs, start, &i, &y);
	  last = start;
	  start->next = xmalloc(sizeof(t_instance));
	  start = start->next;
	  i++;
	}
  free(last->next);
  last->next = NULL;
  return (current);
}

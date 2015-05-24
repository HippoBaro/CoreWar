/*
** Host.c for Corewar in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Apr 24 03:05:32 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:09:27 2015 Hippolyte Barraud
*/

#include        "op.h"
#include        "corewar.h"

static int	GetChampionCount(t_instance *instances)
{
  int           out;
  t_instance	*tmp;

  out = 0;
  tmp = instances;
  while (tmp != NULL)
    {
      if (tmp->Parent == -1)
	out++;
      tmp = tmp->next;
    }
  return (out);
}

static int	ExecuteFunction(t_instance *instance, t_vm *vm, int *index,
				ACTIONPTR)
{
  int           arg[4];
  char          type[4];
  int           nb;
  int           ptr_i;

  ptr_i = VM_MEMORY_ADRESS(*index + 1);
  if (vm->Index > 0)
    {
      nb = (vm->MemoryMap)[VM_MEMORY_ADRESS(ptr_i)];
      nb = GetByteAt(type, nb);
      FillTypeArray(vm->CurrentAction, type);
      ptr_i++;
      FillArgsForAction(vm->MemoryMap, &ptr_i, arg, nb, type);
    }
  else if (!(vm->Index))
    FillArgsArrayIndex(vm->MemoryMap, &ptr_i, arg, vm->CurrentAction);
  nb = (vm->MemoryMap)[*index] - 1;
  if (nb < 16 && nb >= 0)
    (FunctionArray[nb])(vm, instance, type, arg);
  else
    PrintError("Skipped illegal instruction. Reason : Unknown function",
	       FALSE);
  if (vm->CurrentAction != ZJMP || instance->Carry == 0)
    instance->PC = ptr_i;
  return (0);
}

static t_instance	*InitCycle(t_vm *vm, int *max)
{
  t_instance *instance;

  instance = vm->champs;
  *max = -1;
  return (instance);
}

static int	CycleAction(t_vm *vm, ACTIONPTR, int cycle)
{
  int           pc;
  t_instance    *champ;
  char          *mem;
  int		max;
  int           time_act;

  champ = InitCycle(vm, &max);
  mem = vm->MemoryMap;
  while (champ != NULL)
	{
	  pc = champ->PC;
	  time_act = GetDelayForAction(mem[pc]);
	  if (max == -1 || time_act < max)
		max = time_act;
	  if ((champ->CurrentCycle + time_act) <= cycle && mem[pc] >= 0
		  && mem[pc] < 16)
		{
		  vm->Index = GetTypeForAction(mem[pc]);
		  vm->CurrentAction = mem[pc];
		  ExecuteFunction(champ, vm, &pc, FunctionArray);
		  champ->CurrentCycle = cycle;
		}
	  champ = champ->next;
	}
  return (max);
}

void	StartVirtualMachine(t_vm *vm)
{
  int	cycle;
  void	(*FunctionArray[16])(t_vm *vm, t_instance *champ, char type[4],
			     int argv[4]);

  SetActionTab(FunctionArray, vm);
  while (GetChampionCount(vm->champs) > 1)
    {
      cycle = InitChampions(vm);
      while (cycle < vm->CycleToDie && vm->LiveCount < NBR_LIVE)
	{
	  CycleAction(vm, FunctionArray, cycle);
	  cycle++;
	  vm->CycleForTurn++;
	  if (vm->CycleForTurn == vm->CycleMax)
	    DumpMemoryOnScreen(vm->MemoryMap);
	}
      if (vm->LiveCount)
	vm->CycleToDie -= CYCLE_DELTA;
      GetChampionCount(vm->champs);
      DisposeInstances(vm);
    }
  PrintMatchResult(vm);
}

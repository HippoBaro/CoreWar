/*
** SetupVM.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:05:11 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:08:04 2015 Hippolyte Barraud
*/

#include "corewar.h"

static bool    	DumpInstance(char *memory, char *fileURI)
{
  int		fd;
  int		i;
  int		y;
  char		buf[2200];

  i = y = 0;
  if ((fd = open(fileURI, O_RDONLY)) == -1)
    return (FALSE);
  read(fd, buf, 2192);
  if (*(int*)buf != -209458688)
    exit(EXIT_FAILURE);
  while (read(fd, buf, 128))
    {
      while (i < 128)
	{
	  memory[y % MEM_SIZE] = buf[i];
	  y++;
	  i++;
	}
      i = 0;
    }
  close(fd);
  return (TRUE);
}

static void    	DumpInstances(char *mem, t_instance *instances,
			      int *memoryPtr, int gap, int instanceCount)
{
  int		max;

  max = 0;
  while (instances && max < instanceCount)
    {
      if (memoryPtr[max] != -1)
	{
	  if (!DumpInstance(mem + (memoryPtr[max] % MEM_SIZE), instances->Name))
	    PrintError("One champion's binary file is unreachable", TRUE);
	  instances->PC = (memoryPtr[max] % MEM_SIZE);
	}
      else
	{
	  if (!DumpInstance(mem + (gap * max), instances->Name))
	    PrintError("One champion's binary file is unreachable", TRUE);
	  instances->PC = (max * gap);
	}
      instances = instances->next;
      max++;
    }
}

static void    	InitialMemoryDump(char *mem, t_instance *instance,
				  int *memoryPtr)
{
  t_instance	*begin;
  int		max;
  int		esp;

  begin = instance;
  max = esp = 0;
  while (MEM_SIZE - 1 - max >= 0)
    {
      mem[MEM_SIZE - 1 - max] = 0;
      max++;
    }
  max = 0;
  while (instance)
    {
      max++;
      instance = instance->next;
    }
  if (max)
    esp = MEM_SIZE / max;
  if (max < 2)
    PrintError("Specifying at least two valid champions is mandatory", TRUE);
  SECSEC();
  DumpInstances(mem, begin, memoryPtr, esp, max);
}

t_vm		*Setup_VM(char **argv)
{
  t_instance	*firstInstance;
  t_vm		*vm;

  vm = xmalloc (sizeof(t_vm));
  vm->MemoryMap = xmalloc(MEM_SIZE);
  firstInstance = CreateInstances(GetArgs('n', argv), argv);
  InitialMemoryDump(vm->MemoryMap, firstInstance, GetArgs('a', argv));
  vm->champs = firstInstance;
  vm->CycleMax = GetArgValue('d', argv, 0);
  vm->CycleToDie = CYCLE_TO_DIE;
  vm->LiveCount = vm->InstanceCount = 0;
  while (firstInstance && (firstInstance = firstInstance->next))
    vm->InstanceCount++;
  return (vm);
}

/*
** Dispose.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:05:24 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:05:24 2015 Hippolyte Barraud
*/

#include        "op.h"
#include        "corewar.h"

static void	DisposeOfInstance_Helper(t_instance *tmp, int *pass)
{
  t_instance	*tmp2;

  pass[0] = 1;
  tmp2 = tmp->next;
  tmp->next = tmp2->next;
  free(tmp2);
}

static t_instance	*DisposeInstance(t_instance *instances, int *pass)
{
  t_instance		*tmp;
  t_instance		*tmp2;

  tmp = instances;
  if (tmp->LastLive == 0)
    {
      tmp = tmp->next;
      pass[0] = 1;
      free(instances);
      return (tmp);
    }
  tmp2 = tmp;
  tmp = tmp->next;
  while (tmp != NULL)
    {
      if (tmp->LastLive == 0)
        {
	  DisposeOfInstance_Helper(tmp2, pass);
          return (instances);
        }
      tmp2 = tmp;
      tmp = tmp->next;
    }
  return (instances);
}

void            DisposeInstances(t_vm *vm)
{
  t_instance	*tmp;
  int		pass;

  pass = 1;
  tmp = vm->champs;
  while (pass != 0)
    {
      pass = 0;
      if (tmp != NULL && tmp->next != NULL)
	tmp = DisposeInstance(tmp, &pass);
    }
  vm->champs = tmp;
}

void	DumpMemoryOnScreen(char *memory)
{
  int	i;
  int	j;

  i = -32;
  while ((i += 32) < MEM_SIZE)
    {
      j = -1;
      while (++j < 32 && i + j < MEM_SIZE)
	{
	  if (j != 0)
	    my_putchar(' ');
	  my_putchar("0123456789ABCDEF"[(memory[i + j] >> 4) & 0xF]);
	  my_putchar("0123456789ABCDEF"[memory[i + j] & 0xF]);
	}
      my_putchar('\n');
    }
  exit(EXIT_SUCCESS);
}

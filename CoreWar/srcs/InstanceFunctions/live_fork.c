/*
** live_fork.c for Corewa in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:04:22 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:04:23 2015 Hippolyte Barraud
*/

#include	"corewar.h"

void   	my_cpy_last_l(char name[], char *s)
{
  int  	i;
  int  	n;

  i = 0;
  if (s == NULL)
    return;
  while (s[i + 1])
    i++;
  while (i >= 0 && s[i] != '/')
    i--;
  if (s[i] == '/')
    i++;
  n = 0;
  while (n < 80 && s[i])
    {
      name[n] = s[i];
      n++;
      i++;
    }
  name[n] = '\0';
}

void		live(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  t_instance	*it;

  (void)type;
  my_printf("Player %d is alive (%d)\n", champ->InstanceIndex, argv[0]);
  it = arena->champs;
  while (it && it->InstanceNumber != *argv)
    it = it->next;
  if (it)
    {
      it->LastLive = 1;
      it->LiveCount++;
      arena->LiveCount++;
      my_cpy_last_l(arena->InstanceNameForLastAction, it->Name);
    }
}

void		my_fork(t_vm *arena, t_instance *champ, char type[4],
			int argv[4])
{
  t_instance	*elm;

  (void)type;
  elm = xmalloc(sizeof(*elm));
  if (VERBOSE)
    my_printf("fork (%d)\n", argv[0]);
  *elm = *champ;
  elm->next = arena->champs;
  elm->InstanceNumber = ++arena->InstanceCount;
  elm->Parent = champ->InstanceNumber;
  elm->PC = VM_MEMORY_ADRESS(champ->PC + (argv[0] % IDX_MOD));
  arena->champs = elm;
}

void		lfork(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  t_instance	*elm;

  (void)type;
  elm = xmalloc(sizeof(*elm));
  if (VERBOSE)
    my_printf("lfork (%d)\n", argv[0]);
  champ->Carry = 0;
  *elm = *champ;
  elm->next = arena->champs;
  elm->InstanceNumber = ++arena->InstanceCount;
  elm->Parent = champ->InstanceNumber;
  elm->PC = VM_MEMORY_ADRESS(champ->PC + argv[0]);
  arena->champs = elm;
}

/*
** aff_zjmp.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 02:52:50 2015 Hippolyte Barraud
** Last update Fri Apr 24 02:53:08 2015 Hippolyte Barraud
*/

#include	"corewar.h"

void	aff(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  (void)arena;
  (void)type;
  if (!REG_VALID(argv[0]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  my_putchar(champ->Args[argv[0]] % 256);
}

void   	zjmp(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  (void)type;
  (void)arena;
  if (VERBOSE)
    my_printf("zjmp (%d) carry=%d\n", argv[0], champ->Carry);
  if (champ->Carry == 1)
    champ->PC += argv[0] % IDX_MOD;
}

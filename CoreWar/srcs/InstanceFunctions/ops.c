/*
** ops.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:04:36 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:04:36 2015 Hippolyte Barraud
*/

#include	"corewar.h"

void	add(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  (void)arena;
  (void)type;
  if (!REG_VALID(argv[0]) || !REG_VALID(argv[1]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (VERBOSE)
    my_printf("add (r%d=%d + r%d=%d -> ",
	      argv[0], champ->Args[argv[0]], argv[1], champ->Args[argv[1]]);
  champ->Args[argv[2]] = champ->Args[argv[0]] + champ->Args[argv[1]];
  champ->Carry = (champ->Args[argv[2]] == 0);
  if (VERBOSE)
    my_printf("r%d=%d) carry=%d\n", argv[2], champ->Args[argv[2]],
	      champ->Carry);
}

void   	sub(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  (void)arena;
  (void)type;
  if (!REG_VALID(argv[0]) || !REG_VALID(argv[1]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (VERBOSE)
    my_printf("sub (r%d=%d - r%d=%d -> ",
	      argv[0], champ->Args[argv[0]], argv[1], champ->Args[argv[1]]);
  champ->Args[argv[2]] = champ->Args[argv[0]] - champ->Args[argv[1]];
  champ->Carry = (champ->Args[argv[2]] == 0);
  if (VERBOSE)
    my_printf("r%d=%d) carry=%d\n", argv[2], champ->Args[argv[2]],
	      champ->Carry);
}

void   	and(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  (void)arena;
  (void)type;
  if (!REG_VALID(argv[0]) || !REG_VALID(argv[1]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (VERBOSE)
    my_printf("and (r%d=%d & r%d=%d -> ",
	      argv[0], champ->Args[argv[0]], argv[1], champ->Args[argv[1]]);
  champ->Args[argv[2]] = champ->Args[argv[0]] & champ->Args[argv[1]];
  champ->Carry = (champ->Args[argv[2]] == 0);
  if (VERBOSE)
    my_printf("r%d=%d) carry=%d\n", argv[2], champ->Args[argv[2]],
	      champ->Carry);
}

void   	or(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  (void)arena;
  (void)type;
  if (!REG_VALID(argv[0]) || !REG_VALID(argv[1]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (VERBOSE)
    my_printf("or (r%d=%d | r%d=%d -> ",
	      argv[0], champ->Args[argv[0]], argv[1], champ->Args[argv[1]]);
  champ->Args[argv[2]] = champ->Args[argv[0]] | champ->Args[argv[1]];
  champ->Carry = (champ->Args[argv[2]] == 0);
  if (VERBOSE)
    my_printf("r%d=%d) carry=%d\n", argv[2], champ->Args[argv[2]],
	      champ->Carry);
}

void   	xor(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  (void)arena;
  (void)type;
  if (!REG_VALID(argv[0]) || !REG_VALID(argv[1]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (VERBOSE)
    my_printf("xor (r%d=%d ^ r%d=%d -> ",
	      argv[0], champ->Args[argv[0]], argv[1], champ->Args[argv[1]]);
  champ->Args[argv[2]] = champ->Args[argv[0]] ^ champ->Args[argv[1]];
  champ->Carry = (champ->Args[argv[2]] == 0);
  if (VERBOSE)
    my_printf("r%d=%d) carry=%d\n", argv[2], champ->Args[argv[2]],
	      champ->Carry);
}

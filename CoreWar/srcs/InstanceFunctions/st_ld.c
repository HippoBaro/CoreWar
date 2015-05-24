/*
** st_ld.c for CoreWar in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Apr 24 02:59:11 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:02:07 2015 Hippolyte Barraud
*/

#include	"corewar.h"

static void	print_int(char *mem, int nb)
{
  mem[0] = (nb >> 24) & 0xFF;
  mem[1] = (nb >> 16) & 0xFF;
  mem[2] = (nb >> 8) & 0xFF;
  mem[3] = (nb >> 0) & 0xFF;
}

static void	read_int(char *mem, int *nb)
{
  *nb = (unsigned char) mem[0] << 24;
  *nb |= (unsigned char) mem[1] << 16;
  *nb |= (unsigned char) mem[2] << 8;
  *nb |= (unsigned char) mem[3];
}

void		st(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  unsigned int	*addr;
  int		offset;

  if (!REG_VALID(argv[0]) || (type[1] == T_REG && !REG_VALID(argv[1])))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (type[1] == T_REG)
    {
      champ->Args[argv[1]] = champ->Args[argv[0]];
    }
  else
    {
      offset = VM_MEMORY_ADRESS(champ->PC + (argv[1] % IDX_MOD));
      addr = (unsigned int *) &(arena->MemoryMap[offset]);
      print_int((char *) addr, champ->Args[argv[0]]);
    }
}

void		ld(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  unsigned int	*addr;
  int		offset;

  if (!REG_VALID(argv[1]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (type[0] == T_IND)
    {
      offset = VM_MEMORY_ADRESS(champ->PC + (*argv % IDX_MOD));
      addr = (unsigned int *) &(arena->MemoryMap[offset]);
      read_int((char *) addr, &(champ->Args[argv[1]]));
    }
  else
    {
      champ->Args[argv[1]] = argv[0];
    }
  champ->Carry = champ->Args[argv[1]] == 0;
}

void		lld(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  unsigned int	*addr;

  if (!REG_VALID(argv[1]))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (type[0] == T_IND)
    {
      addr = (unsigned int *) &(arena->MemoryMap[VM_MEMORY_ADRESS
						 (champ->PC + *argv)]);
      read_int((char *) addr, &(champ->Args[argv[1]]));
    }
  else
    {
      champ->Args[argv[1]] = argv[0];
    }
  champ->Carry = champ->Args[argv[1]] == 0;
}

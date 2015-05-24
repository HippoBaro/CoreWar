/*
** sti_ldi.c for Corewar in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Apr 24 02:56:05 2015 Hippolyte Barraud
** Last update Fri Apr 24 02:59:03 2015 Hippolyte Barraud
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

void		sti(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  int		offset;
  unsigned int	*addr;

  if (!REG_VALID(argv[0]) || ((type[1] == T_REG && !REG_VALID(argv[1]))) ||
      (type[2] == T_REG && !REG_VALID(argv[2])))
    {
      PrintError("Skipped illegal instruction. Reason : Illegal register",
		 FALSE);
      return;
    }
  if (VERBOSE)
    my_printf("sti (r%d=%d -> i@pc+(", argv[0], champ->Args[argv[0]]);
  offset = type[1] == T_REG ? champ->Args[argv[1]] : argv[1];
  if (VERBOSE)
    my_printf(type[1] == T_REG ? "r%d=" : "d=%d", argv[1]);
  if (type[1] == T_REG && VERBOSE)
    my_printf("%d", champ->Args[argv[1]]);
  offset += type[2] == T_REG ? champ->Args[argv[2]] : argv[2];
  if (type[2] == T_REG && VERBOSE)
    my_printf("%d", champ->Args[argv[2]]);
  addr = (unsigned int *) &(arena->MemoryMap[VM_MEMORY_ADRESS(champ->PC
							      + offset)]);
  print_int((char *) addr, champ->Args[*argv]);
}

void		ldi(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  short		*ad;
  int		i;
  unsigned int	*addr;

  (void)type;
  if (VERBOSE)
    my_printf("ldi %d %d %d\n", argv[0], argv[1], argv[2]);
  ad = (short *) &(arena->MemoryMap[VM_MEMORY_ADRESS(champ->PC
						     + (*argv % IDX_MOD))]);
  i = *ad + argv[1];
  addr = (unsigned int *) &(arena->MemoryMap[VM_MEMORY_ADRESS
					     (champ->PC + (i % IDX_MOD))]);
  if (REG_VALID(argv[2]))
    read_int((char *) addr, &(champ->Args[argv[2]]));
  champ->Carry = REG_VALID(argv[2]) ? (champ->Args[argv[2]] == 0) : 0;
}

void		lldi(t_vm *arena, t_instance *champ, char type[4], int argv[4])
{
  short		*ad;
  int		i;
  unsigned int	*addr;

  (void)type;
  if (VERBOSE)
    my_printf("lldi %d %d %d\n", argv[0], argv[1], argv[2]);
  ad = (short *) &(arena->MemoryMap[VM_MEMORY_ADRESS(champ->PC + *argv)]);
  i = *ad + argv[1];
  addr = (unsigned int *) &(arena->MemoryMap[VM_MEMORY_ADRESS(champ->PC + i)]);
  if (REG_VALID(argv[2]))
    read_int((char *) addr, &(champ->Args[argv[2]]));
  champ->Carry = REG_VALID(argv[2]) ? (champ->Args[argv[2]] == 0) : 0;
}

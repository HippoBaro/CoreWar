/*
** ParserArgs.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:05:57 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:05:58 2015 Hippolyte Barraud
*/

#include        "op.h"
#include        "corewar.h"

int		FillByteChar(char *memory, int *index)
{
  unsigned char out;

  out = (unsigned char)memory[*index];
  *index = VM_MEMORY_ADRESS(*index + 1);
  return ((int)out);
}

int	Fill8BitShort(char *memory, int *index, int lenght)
{
  short	out;
  int	current;

  current = lenght;
  while (lenght)
    {
      if (current == lenght)
        out = (unsigned char)memory[*index];
      else
        {
          out = out << 8;
          out = (unsigned char)memory[*index] | out;
        }
      *index = VM_MEMORY_ADRESS(*index + 1);
      lenght--;
    }
  return ((int)out);
}

int	Fill8BitInt(char *memory, int *index, int lenght)
{
  int  	out;
  int	current;

  current = lenght;
  while (lenght)
    {
      if (current == lenght)
        out = (unsigned char)memory[*index];
      else
        {
          out = out << 8;
          out = (unsigned char)memory[*index] | out;
        }
      *index = VM_MEMORY_ADRESS(*index + 1);
      lenght--;
    }
  return ((int)out);
}

static void	FillArgsArray(char *memory, int *index, int args[], int lenght)
{
  if (lenght == 1)
    args[0] = FillByteChar(memory, index);
  else if (lenght == 2)
    args[0] = Fill8BitShort(memory, index, lenght);
  else if (lenght == 4)
    args[0] = Fill8BitInt(memory, index, lenght);
  args[1] = '\0';
}

void	FillArgsArrayIndex(char *memory, int *index, int args[], char action)
{
  if (action == LIVE)
    FillArgsArray(memory, index, args, 4);
  else if (action == ZJMP)
    FillArgsArray(memory, index, args, IND_SIZE);
  else if (action == FORK || action == LFORK)
    FillArgsArray(memory, index, args, IND_SIZE);
}

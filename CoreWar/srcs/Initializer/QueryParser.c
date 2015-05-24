/*
** QueryParser.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 03:05:01 2015 Hippolyte Barraud
** Last update Fri Apr 24 03:05:02 2015 Hippolyte Barraud
*/

#include "corewar.h"

int	GetArgValue(char valueCode, char **argv, int lenght)
{
  int	i;
  int  	nb;

  i = nb = 0;
  while (argv[i])
    {
      if (argv[i][0] == '-' && argv[i][1] == valueCode)
	{
	  if (nb >= lenght)
	    {
	      if (argv[i + 1])
		return (my_getnbr(argv[i + 1]));
	    }
	  nb++;
	}
      i++;
    }
  return (ERROR);
}

int	*GetArgs(char valueCode, char **argv)
{
  int  	i;
  int  	*out;

  i = 0;
  out = xmalloc(4);
  while (i < 4)
    {
      out[i] = GetArgValue(valueCode, argv, i);
      i++;
    }
  return (out);
}

char   	*GetInstanceName(char **argv, int lenght)
{
  int  	i;
  int  	nb;

  nb = 0;
  i = 1;
  while (argv[i])
    {
      if (argv[i][0] != '-' && i >= 1 && argv[i - 1][0] != '-')
	{
	  if (nb >= lenght)
	    return (argv[i]);
	  nb++;
	}
      i++;
    }
  return (NULL);
}

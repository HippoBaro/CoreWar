/*
** main.c for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 02:42:44 2015 Hippolyte Barraud
** Last update Fri Apr 24 02:42:57 2015 Hippolyte Barraud
*/

#include "corewar.h"

int	main(int argc, char **argv)
{
  (void)argc;
  StartVirtualMachine(Setup_VM(argv));
  return (EXIT_SUCCESS);
}

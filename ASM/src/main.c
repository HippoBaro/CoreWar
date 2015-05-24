/*
** main.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 15:57:57 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:35:38 2015 Hippolyte Barraud
*/

#include        "corewar.h"

static void     treat_file(char *path)
{
  int           fd;
  char	        **label_index;
  t_cmd     	*op_start;
  t_cmd     	*op_end;

  label_index = xmalloc(sizeof(char *) * 512);
  op_start = op_end = NULL;
  if ((fd = open(path, O_RDONLY)) == -1)
    return;
  if (asm_loop(fd, &op_start, &op_end, label_index))
    return;
  close(fd);
  compile(op_start, path);
  free(label_index);
}

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  if (argc < 2)
    my_putstr("Usage : ./asm [path to .s] [...]\n");
  while (++i < argc)
    treat_file(argv[i]);
  return (0);
}

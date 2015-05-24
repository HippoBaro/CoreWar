/*
** write_to_file.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 16:00:26 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:36:47 2015 Hippolyte Barraud
*/

#include        "corewar.h"

static char     *get_output_path(char *old)
{
  int           len;
  int           i;
  char          *new;

  len = my_strlen(old);
  if (len >= 2 && old[len - 1] == 's' && old[len - 2] == '.')
    old[len - 2] = '\0';
  new = xmalloc(my_strlen(old) + 5);
  len = -1;
  while (old[++len])
    new[len] = old[len];
  i = -1;
  while (++i < 5)
    new[i + len] = ".cor"[i];
  return (new);
}

static void     write_header(char *header[2], int size, int fd)
{
  int           i;
  char          c;

  write(fd, COREWAR_EXEC_MAGIC_CHAR, 4);
  i = -1;
  while (++i < 132 && header[1] && header[1][i] != '\0');
  if (header[1])
    write(fd, header[1], i);
  while (i++ < 132)
    write(fd, "", 1);
  i = -1;
  while (++i < 4)
    {
      c = ((char *)&size)[3 - i];
      write(fd, &c, 1);
    }
  i = -1;
  while (++i < 2052 && header[0] && header[0][i] != '\0');
  if (header[0])
    write(fd, header[0], i);
  while (i++ < 2052)
    write(fd, "", 1);
}

bool		export_bin(t_cmd *line, char *header[2], int size, char *path)
{
  t_cmd		*next;
  int           fd;
  char          *dest;

  if ((dest = get_output_path(path)) == NULL)
    return (FAILURE);
  if ((fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    return (FAILURE);
  write_header(header, size, fd);
  while (line)
    {
      if (line->bin_size + 1 > 0
	  && write(fd, line->bin, line->bin_size + 1) == -1)
        my_putstr("Write error\n");
      line = line->next;
    }
  free(dest);
  close(fd);
  while (line)
    {
      next = line->next;
      free(line);
      line = next;
    }
  return (SUCCES);
}

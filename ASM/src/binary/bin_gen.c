/*
** write_asm.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 15:59:51 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:19:05 2015 Hippolyte Barraud
*/

#include        "corewar.h"

static void     labels_loop(t_cmd *line, t_cmd *lbls,
                            int i[3], int *lsize)
{
  t_cmd		*it;

  while (++i[0] < 4 && line->arg.type[*i] != 0)
    {
      i[1] = get_arg_size(line->cmd_code, *i, line->arg.type[*i]);
      if (line->arg.type[*i] == T_LAB || line->arg.argv[*i][0] == LABEL_CHAR)
        {
          it = lbls;
          while (it && my_strcmp(line->arg.argv[*i] + 1, it->arg.argv[0]))
            it = it->next;
          if (it)
            fill_arg(line, lsize, it->bin_size - i[2], i[1]);
          else
	    syntax_prompt("Label undifined", line->line, *i, TRUE);
        }
      else
        *lsize += i[1];
    }
}

static void	replace_labels(t_cmd *line, t_cmd *lbls)
{
  int           i[3];
  int           lsize;

  i[2] = 0;
  while (line != NULL)
    {
      if (line->cmd_code > T_NONE)
        {
          *i = -1;
          lsize = (line->cmd_code != T_REG && line->cmd_code != 9 &&
                   line->cmd_code != 12 && line->cmd_code != 15);
          labels_loop(line, lbls, i, &lsize);
          i[2] += line->bin_size + 1;
        }
      line = line->next;
    }
}

static void     treat_asm(t_cmd *line, char *header[2],
                          t_cmd *asms[3], int *pos)
{
  int           i;

  if (line->cmd_code == T_LABEL)
    {
      list_replace_node(asms, &asms[2], line);
      line->bin_size = *pos;
    }
  else if (line->cmd_code == T_NAME || line->cmd_code == T_COMMENT)
    header[line->cmd_code + 3] = line->arg.argv[0];
  else
    {
      line->bin_size = -1;
      line->bin[++(line->bin_size)] = line->cmd_code;
      if (line->cmd_code != T_REG && line->cmd_code != 9 &&
          line->cmd_code != 12 && line->cmd_code != 15)
        fill_arg_type(line, &(line->bin_size));
      i = -1;
      while (++i < MAX_ARGS_NUMBER && line->arg.type[i] != 0)
        fill_arg(line, &(line->bin_size), my_getnbr(line->arg.argv[i]),
                 get_arg_size(line->cmd_code, i, line->arg.type[i]));
      *pos += line->bin_size + 1;
    }
}

void	compile(t_cmd *line, char *path)
{
  char	*header[2];
  t_cmd	*asms[3];
  int	pos;

  header[0] = header[1] = NULL;
  asms[2] = NULL;
  pos = 0;
  *asms = line;
  while (line)
    {
      line->bin_size = -1;
      asms[1] = line->next;
      treat_asm(line, header, asms, &pos);
      line = asms[1];
    }
  replace_labels(*asms, asms[2]);
  export_bin(*asms, header, pos, path);
  my_putstr(GREEN "Compilation succeed.\n" BLANK);
  my_putstr("Output file : ");
  my_putstr(path);
  my_putstr(".cor");
  my_putchar('\n');
}

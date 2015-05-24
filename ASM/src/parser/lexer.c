/*
** parsing.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 15:58:56 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:22:29 2015 Hippolyte Barraud
*/

#include        "corewar.h"

static char     get_command_id(char *command)
{
  int           i;

  i = 0;
  while (op_tab[i].code)
    {
      if (my_strcmp(command, op_tab[i].mnemonique) == 0)
        return (op_tab[i].code);
      i++;
    }
  my_putstr("Error: \"");
  my_putstr(command);
  my_putstr("\" command invalid.\n");
  exit(0);
  return (0);
}

static void     get_command_arg_type(char **words, char *types)
{
  int           i;

  i = 0;
  while (i < 4 && words[i] && words[i][0])
    {
      if (words[i][0] == 'r')
        types[i] = T_REG;
      else if (words[i][0] == DIRECT_CHAR)
        {
          if (words[i][1] == LABEL_CHAR)
            types[i] = T_LAB;
          else
            types[i] = T_DIR;
        }
      else
        types[i] = T_IND;
      i++;
    }
  while (i < 4)
    {
      types[i] = 0;
      i++;
    }
}

static void     get_command_args(char **words, char **argv)
{
  int           i;
  int           y;

  i = y = 0;
  while (i < 4 && words[i] && words[i][0])
    {
      if (words[i][0] == 'r' || words[i][0] == DIRECT_CHAR)
        words[i] = words[i] + 1;
      argv[i] = words[i];
      i++;
    }
  if (i < 4)
    argv[i] = NULL;
}

void	get_code(char **words, t_cmd *line, char **s)
{
  if (!my_strcmp(words[0], NAME_CMD_STRING))
    line->cmd_code = T_NAME;
  else if (!my_strcmp(words[0], COMMENT_CMD_STRING))
    line->cmd_code = T_COMMENT;
  else
    line->cmd_code = T_NONE;
  *s = *s + 3;
}

bool	is_command(char **words, char *s, t_cmd *line, char **label_index)
{
  char	*lbl;

  if (words[0] && is_label(words[0]))
    {
      line->cmd_code = T_LABEL;
      lbl = my_strdup(words[0]);
      get_command_args(words, line->arg.argv);
      line->arg.argv[0] = lbl;
      (void)label_index;
    }
  else if (words[0] && words[1])
    {
      line->cmd_code = get_command_id(words[0]);
      get_command_arg_type(words + 1, line->arg.type);
      get_command_args(words + 1, line->arg.argv);
    }
  else
    return (FALSE);
  if (line->cmd_code > T_NONE)
    check_args(line, s);
  return (TRUE);
}

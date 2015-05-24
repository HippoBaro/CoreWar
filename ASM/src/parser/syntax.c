/*
** verif.c for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 15:59:19 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:24:59 2015 Hippolyte Barraud
*/

#include        "corewar.h"

static void     check_label(char *s)
{
  int           i;
  int           y;

  i = y = 0;
  while (s[i] && s[i] != ':')
    {
      if (i == 0 && (ISNUM(s[i])))
    	syntax_prompt("Label cannot start with digit", s, -1, TRUE);
      while (LABEL_CHARS[y] && LABEL_CHARS[y] != s[i])
        y++;
      if (!LABEL_CHARS[y])
    	syntax_prompt("Forbidden character in label", s, -1, TRUE);
      y = 0;
      i++;
    }
  if (s[i] == 0 || s[i + 1] != 0)
    syntax_prompt("Unexpected character after label declaration", s, -1, TRUE);
  if (i == 0)
    syntax_prompt("Label name missing", s, -1, TRUE);
}

bool	is_label(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == LABEL_CHAR)
        {
          check_label(str);
          return (TRUE);
        }
      i++;
    }
  return (FALSE);
}

void	check_arg_value(t_cmd *line, int nbr_arg, char *s)
{
  if (line->arg.type[nbr_arg] == T_REG
      && (my_getnbr(line->arg.argv[nbr_arg]) >= REG_NUMBER
	  || my_getnbr(line->arg.argv[nbr_arg]) < 0))
    syntax_prompt("Register does not exits", s, nbr_arg, FALSE);
  else if (line->arg.type[nbr_arg] == T_DIR
	   && (my_getnbr(line->arg.argv[nbr_arg]) > INT_MAX
	       || my_getnbr(line->arg.argv[nbr_arg]) < INT_MIN))
    syntax_prompt("Direct overflow", s, nbr_arg, FALSE);
}

void	check_args(t_cmd *line, char *s)
{
  int	nbr_arg;
  bool	is_reg;

  nbr_arg = 0;
  while (nbr_arg++ <= 3 && line->arg.argv[nbr_arg]);
  if (op_tab[line->cmd_code - 1].nbr_args != nbr_arg)
    syntax_prompt("Unexpected argument number", s, -1, TRUE);
  nbr_arg = 0;
  while (nbr_arg <= 3 && line->arg.argv[nbr_arg])
    {
      check_arg_value(line, nbr_arg, s);
      is_reg = FALSE;
      if ((line->arg.type[nbr_arg] & T_LAB) > 0)
        {
          is_reg = TRUE;
          line->arg.type[nbr_arg] = T_DIR;
        }
      if ((op_tab[line->cmd_code - 1].type[nbr_arg]
	   & line->arg.type[nbr_arg]) == 0)
    	syntax_prompt("Illegal type of argument", s, nbr_arg, TRUE);
      if (is_reg)
        line->arg.type[nbr_arg] = T_LAB;
      nbr_arg++;
    }
}

bool	is_string_def(t_cmd *line, char *s, char **words)
{
  int	i;

  get_code(words, line, &s);
  if (line->cmd_code != T_NONE)
    {
      while (*s && *(s - 1) != '\"')
	s++;
      line->arg.argv[0] = xmalloc(my_strlen(s) + 1);
      i = 0;
      while (*s && *s != '\"')
	line->arg.argv[0][i++] = *s++;
      line->arg.argv[0][i] = '\0';
      line->arg.argv[1] = NULL;
      return (TRUE);
    }
  return (FALSE);
}

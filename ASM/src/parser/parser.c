/*
** parser.c for ASM in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Tue Mar 24 16:50:25 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:50:43 2015 Hippolyte Barraud
*/

#include        "corewar.h"

static bool      parse_line(char *s, t_cmd *line, char **label_index,
			    bool ignore_flag)
{
  char          **words;
  int           i;

  i = -1;
  while (s[++i])
    if (s[i] == COMMENT_CHAR || s[i] == ';')
      s[i--] = '\0';
  words = my_str_to_wordtab(s);
  if (ignore_flag)
    words = words + 1;
  if (words[0] && !is_string_def(line, s, words))
    {
      if (!is_command(words, s, line, label_index))
        return (FALSE);
    }
  else if (!words || !words[0])
    return (FALSE);
  return (TRUE);
}

bool	asm_loop(int fd, t_cmd **op_start, t_cmd **op_end, char **label_index)
{
  char	*str;
  t_cmd	*current_op;

  while ((str = get_next_line(fd)))
    {
      current_op = xmalloc(sizeof(t_cmd));
      current_op->line = str;
      if (parse_line(str, current_op, label_index, FALSE))
        {
          list_add_node(op_start, op_end, current_op);
          if (current_op->cmd_code == -1 && current_op->arg.argv[1])
            {
              current_op = xmalloc(sizeof(t_cmd));
              parse_line(str, current_op, label_index,TRUE);
              list_add_node(op_start, op_end, current_op);
            }
        }
      else
        free(current_op);
    }
  return (SUCCES);
}

/*
** corewar.h for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM/include
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 16:04:00 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:09:41 2015 Hippolyte Barraud
*/

#ifndef _COREWAR_H_
# define _COREWAR_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "op.h"
#include "my.h"

# define	RED	       		"\033[1;31m"
# define	GREEN	       		"\033[1;32m"
# define	CYAN	       		"\033[1;36m"
# define	BLUE	       		"\033[1;34m"
# define	YELLOW	       		"\033[1;33m"
# define	BLANK	       		"\033[0m"

# define	TRUE			1
# define	FALSE			0
# define	FAILURE			1
# define	SUCCES			0

typedef	unsigned char	bool;

typedef struct          s_arg
{
  char                  type[MAX_ARGS_NUMBER];
  char                  *argv[MAX_ARGS_NUMBER];
}                       t_arg;

typedef struct          s_cmd
{
  unsigned char         bin[20];
  int                   bin_size;
  char                  cmd_code;
  t_arg			arg;
  char 		       	*line;
  struct s_cmd      	*next;
}                       t_cmd;

bool  	asm_loop(int fd, t_cmd **op_start, t_cmd **op_end, char **label_index);
void    get_code(char **words, t_cmd *line, char **s);
bool	is_command(char **words, char *s, t_cmd *line, char **label_index);
bool	is_string_def(t_cmd *line, char *s, char **words);
void    check_args(t_cmd *line, char *s);
void    syntax_prompt(char *desc, char *line, int arg_num, bool isCritical);

void    fill_arg_type(t_cmd *line, int *i);
void    fill_arg(t_cmd *line, int *i, int nb, int size);
int     get_arg_size(int code, int offset, int type);

bool	is_label(char *str);
bool	export_bin(t_cmd *line, char *header[2], int size, char *path);
void    compile(t_cmd *line, char *path);

int     list_add_char(t_char **end, char *str, int len);
int     list_add_node(t_cmd **begin, t_cmd **end, t_cmd *elm);
int     list_replace_node(t_cmd **rmbegin, t_cmd **replace, t_cmd *elm);

void	*xmalloc(const size_t size);

#endif

/*
** my.h for LIBMY in /home/barrau_h/Desktop/WIP/CoreWar/ASM/include
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Thu Mar 19 16:04:54 2015 Hippolyte Barraud
** Last update Tue Mar 24 16:11:19 2015 Hippolyte Barraud
*/

#ifndef _MY_H_
# define _MY_H_

#include "op.h"

#define ISNUM(x)        ((x) >= '0' && (x) <= '9')
#define ISHMAX(x)       ((x) >= 'A' && (x) <= 'F')
#define ISHMIN(x)       ((x) >= 'a' && (x) <= 'f')
#define ISHEX(x)        (ISNUM(x) || ISHMAX(x) || ISHMIN(x))
#define HEX_TO_DEC(x)   (ISNUM(x) ? (x) - 48 :			\
			 (ISHMIN(x) ? (x) - 87 : (x) - 55))
#define IS_SIGN(x)      ((x) == '-' || (x) == '+')
#define IS_SPACE(x)     ((x) == ' ' || (x) == '\t' || (x) == SEPARATOR_CHAR)

#define BUFF_SIZE       1024

typedef struct  s_char
{
  char          *str;
  char          *to_free;
  int           len;
  struct s_char *next;
}               t_char;

void    my_putchar(char c);
void    my_putstr(char *s);
int     my_putnbr(int nb);
int64_t my_getnbr(char *s);

char    *my_strdup(char *s);
int     my_strlen(char *s);
int     my_tablen(char **tab);
int     my_strcmp(char *s1, char *s2);
char    *get_next_line(const int fd);
char    **my_str_to_wordtab(char *str);
int     get_word(char *str, char **dest);

#endif

/*
** my.h for Corewar in /home/barrau_h
** 
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
** 
** Started on  Fri Apr 24 02:41:19 2015 Hippolyte Barraud
** Last update Fri Apr 24 02:41:21 2015 Hippolyte Barraud
*/

#ifndef	__MY_H__
#define	__MY_H__

#include	"corewar.h"
#include	"op.h"

#define	ISNUM(x)	((x) >= '0' && (x) <= '9')
#define	ISHMAX(x)	((x) >= 'A' && (x) <= 'F')
#define	ISHMIN(x)	((x) >= 'a' && (x) <= 'f')
#define	ISHEX(x)	(ISNUM(x) || ISHMAX(x) || ISHMIN(x))
#define	HEX_TO_DEC(x)	(ISNUM(x) ? (x) - 48 : (ISHMIN(x) ? (x) - 87 : (x) - 55))
#define	IS_SIGN(x)	((x) == '-' || (x) == '+')
#define	IS_SPACE(x)	((x) == ' ' || (x) == '\t' || (x) == SEPARATOR_CHAR)

#define	BUFF_SIZE	1024

typedef	struct	s_char
{
  char		*str;
  char		*to_free;
  int		len;
  struct s_char	*next;
}		t_char;

void	my_putchar(char c);
void	my_putstr(char *s);
int	my_putnbr(int nb);
int	my_getnbr(char *s);
void	my_printf(char *s, ...);

char	*my_strdup(char *s);
int	my_strlen(char *s);
int	my_tablen(char **tab);
int	my_strcmp(char *s1, char *s2);
char	*get_next_line(const int fd);
char	**my_str_to_wordtab(char *str);
int	my_push_back(t_char **end, char *str, int len);
int	get_word(char *str, char **dest);

#endif

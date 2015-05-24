/*
** corewar.h for Corewar in /home/barrau_h
**
** Made by Hippolyte Barraud
** Login   <barrau_h@epitech.net>
**
** Started on  Fri Apr 24 02:36:16 2015 Hippolyte Barraud
** Last update Fri Apr 24 02:41:10 2015 Hippolyte Barraud
*/

#ifndef			__COREWAR_H__
# define		__COREWAR_H__

#include 		<sys/types.h>
#include 		<sys/stat.h>
#include 		<signal.h>
#include 		<fcntl.h>
#include 		<unistd.h>
#include		<stdlib.h>
#include		"op.h"
#include		"my.h"

/*
** OPTIONS
*/
# define VERBOSE			FALSE

# define RED	       		"\033[1;31m"
# define GREEN	       		"\033[1;32m"
# define CYAN	       		"\033[1;36m"
# define BLUE	       		"\033[1;34m"
# define YELLOW	       		"\033[1;33m"
# define BLANK	       		"\033[0m"

# define TRUE		       	1
# define FALSE		       	0
# define EQUAL		       	0
# define ERROR		       	-1
# define SUCCESS	       	0

# define LIVE			1
# define LD			2
# define ST			3
# define ADD			4
# define SUB			5
# define AND			6
# define OR			7
# define XOR			8
# define ZJMP			9
# define LDI			10
# define STI			11
# define FORK			12
# define LLD			13
# define LLDI			14
# define LFORK			15

# define ACTIONPTR		void (*FunctionArray[16])(t_vm *VM, t_instance *instance, char type[4], int argv[4])
# define VM_MEMORY_ADRESS(x)	((x) < 0 ? MEM_SIZE - (-(x) % MEM_SIZE) : (x) % MEM_SIZE)
# define SECSEC()		(libmix(STI, &FatalError))
# define REG_VALID(x)		((x) >= 0 && (x) < REG_NUMBER)

# define bool			unsigned char

typedef	struct		s_instance
{
  char			*Name;
  char			*Comment;
  short			InstanceIndex;
  int			InstanceNumber;
  int			Parent;
  int			LastLive;
  int			LiveCount;
  int			Delay;
  int			CurrentCycle;
  char			Carry;
  int			PC;
  int			Args[16];
  struct s_instance	*next;
}			t_instance;

typedef	struct		s_vm
{
  t_instance		*champs;
  int			CycleToDie;
  int			CycleMax;
  int			CycleForTurn;
  int			LiveCount;
  int			InstanceCount;
  char			InstanceNameForLastAction[80];
  unsigned char		CurrentAction;
  int			Index;
  char			*MemoryMap;
}			t_vm;

void    live(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void    ld(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void    st(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	add(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	sub(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	and(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	or(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	xor(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	zjmp(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	ldi(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	sti(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	my_fork(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	lld(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	lldi(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	lfork(t_vm *VM, t_instance *instance, char type[4], int argv[4]);
void   	aff(t_vm *VM, t_instance *instance, char type[4], int argv[4]);

/*
** utils.c
*/
void	*xmalloc(const size_t size);
void 	FatalError(int code);
void 	PrintError(char *message, bool isCritical);
void	PrintMatchResult(t_vm *arena);
bool	CheckArgs(int *argv, int num);

/*
** ParserArgs.c
*/
int    	FillByteChar(char *memory, int *index);
int	Fill8BitShort(char *memory, int *index, int lenght);
int	Fill8BitInt(char *memory, int *index, int lenght);
void	FillArgsArrayIndex(char *memory, int *index, int args[], char action);

/*
** ParserType.c
*/
char	GetByteAt(char types[], unsigned char c);
void	FillTypeArray(char c, char type[]);
void	FillArgsForAction(char *memory, int *i, int arg[], char nb, char type[]);

/*
** Dispose.c
*/
void	DisposeInstances(t_vm *arena);
void	DumpMemoryOnScreen(char *memory);

/*
** Host.c
*/
void	StartVirtualMachine(t_vm *vm);

/*
** Init.c
*/
int	InitChampions(t_vm *vm);
t_instance	*CreateInstances(int *UUIDs, char **argv);

/*
** Rules.c
*/
int	GetDelayForAction(char actionCode);
int	GetTypeForAction(char actionCode);
void	SetActionTab(ACTIONPTR, t_vm *arena);

/*
** QueryParser.c
*/
int	GetArgValue(char valueCode, char **argv, int lenght);
int	*GetArgs(char valueCode, char **argv);
char	*GetInstanceName(char **argv, int lenght);

/*
** SetupVM.c
*/
t_vm    *Setup_VM(char **argv);

#endif

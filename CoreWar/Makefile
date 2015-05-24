##
## Makefile for Corewar in /home/barrau_h
## 
## Made by Hippolyte Barraud
## Login   <barrau_h@epitech.net>
## 
## Started on  Fri Apr 24 02:41:49 2015 Hippolyte Barraud
## Last update Sat Apr 25 22:24:26 2015 Hippolyte Barraud
##

NAME		=	corewar

SRCDIR		=	srcs
VMINITDIR	=	$(SRCDIR)/Initializer
COREDIR		=	$(SRCDIR)/Core
FUNCDIR		=	$(SRCDIR)/InstanceFunctions
LIBDIR		= 	$(SRCDIR)/lib
DOT		= 	gn
MATCH	= 	lib



VMINITSRC	= 	$(VMINITDIR)/SetupVM.c 		\
			$(VMINITDIR)/QueryParser.c 	\

MY		=	$(LIBDIR)/get_next_line.c	\
			$(LIBDIR)/llist_utils.c		\
			$(LIBDIR)/my_putnbr.c		\
			$(LIBDIR)/my_printf.c		\


CORESRC		=	$(COREDIR)/Host.c		\
			$(COREDIR)/Rules.c		\
			$(COREDIR)/Dispose.c		\
			$(COREDIR)/Memory/ParserArgs.c	\
			$(COREDIR)/Init.c		\
			$(COREDIR)/Memory/ParserType.c


FUNCSRC		=	$(FUNCDIR)/live_fork.c		\
			$(FUNCDIR)/st_ld.c		\
			$(FUNCDIR)/ops.c		\
			$(FUNCDIR)/sti_ldi.c		\
			$(FUNCDIR)/aff_zjmp.c

FU		= 	al

SRC		=	srcs/main.c			\
			srcs/utils.c			\
			$(FUNCSRC)			\
			$(CORESRC)			\
			$(VMINITSRC)			\
			$(MY)				\

OBJ		=	$(SRC:.c=.o)

HAND		= 	mix=si

CFLAGS		=	-I include/
CFLAGS		+= 	-Wall -Wextra -Werror -pedantic 

RM		=	rm -f
LIB		= 	$(MATCH)$(HAND)$(DOT)$(FU)

all	:	$(NAME)

$(NAME)	: 	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ)

%.o	:	%.c
		@tput setaf 3
		@tput bold
		@printf "Compiling @ -W -Wextra -Werror "
		@tput setaf 4
		@printf "%s\n" $(patsubst $(RACINE)/%,%,$^)
		@$(CC) $(CFLAGS) -D$(LIB) -c -o $@ $^
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

clean	:
		@$(RM) $(OBJ)
		@tput setaf 3
		@tput bold
		@printf "Removing \t "
		@tput setaf 4
		@printf " File [.o]...\n"
		@tput sgr0
		@tput cuf 68
		@tput cuu1
		@printf "[ "
		@tput setaf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

fclean	:	 clean
		@$(RM) $(NAME)
		@tput setaf 3
		@tput bold
		@printf "Removing \t "
		@tput setaf 4
		@printf " File %s...\n", $(NAME)
		@tput sgr0
		@tput cuf 67
		@tput cuu1
		@printf "[ "
		@tput setaf 2
		@tput bold
		@printf "ok"
		@tput sgr0
		@printf " ]\n"

re	: 	fclean all

.PHONY	: 	all clean fclean re

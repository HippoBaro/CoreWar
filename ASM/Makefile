##
## Makefile for ASM in /home/barrau_h/Desktop/WIP/CoreWar/ASM
## 
## Made by Hippolyte Barraud
## Login   <barrau_h@epitech.net>
## 
## Started on  Thu Mar 19 15:56:28 2015 Hippolyte Barraud
## Last update Tue Mar 24 16:28:19 2015 Hippolyte Barraud
##

CC	=	gcc

PSRC	=	src
PLIB	=	lib
PPARSER	=	$(PSRC)/parser
PBIN	=	$(PSRC)/binary

NAME	=	asm

MY	=	$(PLIB)/get_next_line.c		\
		$(PLIB)/llist_utils.c		\
		$(PLIB)/error.c			\
		$(PLIB)/my_strlen.c		\
		$(PLIB)/my_strcmp.c		\
		$(PLIB)/my_putnbr.c		\
		$(PLIB)/my_strdup.c		\
		$(PLIB)/my_str_to_wordtab.c

SRC	=	$(PSRC)/main.c			\
		$(PPARSER)/parser.c		\
		$(PPARSER)/lexer.c		\
		$(PPARSER)/syntax.c		\
		$(PSRC)/op.c			\
		$(PBIN)/bin_gen.c		\
		$(PBIN)/bin_helper.c		\
		$(PBIN)/export.c		\
		$(MY)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ./include/			\
		-Wall -Wextra			\
		-ansi -pedantic

RM	=	rm -f

all	:	$(NAME)

$(NAME)	: 	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB);

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

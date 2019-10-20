##
## ETNA PROJECT  by group
## Makefile
## File description:
##      This file compiles
##

CC 		= gcc -g3
RM		= /bin/rm -rf
MAKE	= /usr/bin/make

CFLAGS	= -Wall -Werror -Wextra -std=c99

NAME	= abstractvm

SRC	= \
	src/main.c \
	src/basicFunction.c

OBJ	= $(SRC:.c=.o)

all: abstractVM

abstractVM:
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all $(NAME) clean fclean re

##
## ETNA PROJECT  by group
## Makefile
## File description:
##      This file compiles
##

CC 		= gcc 
CCDBG	= gcc -ggdb -g3 -std=c99
RM		= /bin/rm -rf
MAKE	= /usr/bin/make

CFLAGS	= -Wall -Werror -Wextra -std=c99

NAME	= abstractvm

SRC	= \
	src/my/my_putstr.c \
	src/my/my_strdup.c \
	src/my/my_strcpy.c \
	src/my/my_putnbr.c \
	src/my/my_strlen.c \
	src/my/my_putchar.c \
	src/my/my_nbrlen.c \
	src/my/my_strcmp.c \
	src/my/my_getnbr.c \
	src/my/my_strlen2.c \
	src/my/my_getnbr2.c \
	src/my/my_putnbr_base.c \
	src/my_printf_func/unsigned_hexadecimal.c \
	src/my_printf_func/main_function.c \
	src/my_printf_func/unsigned_octal.c \
	src/my/my_printf.c \
	src/my/my_putnbr_unsigned.c \
	src/my_printf_func/flags_func3.c \
	src/my_printf_func/flags_func.c \
	src/my_printf_func/flags_func2.c \
	src/main.c \
	src/basicFunction.c \
	src/fileHandler.c \
	src/avmHandler.c

OBJ	= $(SRC:.c=.o)

all: abstractVM

debug:
	$(CCDBG) $(CFLAGS) -o $(NAME) $(SRC)

lazyd:
	$(CCDBG) -o $(NAME) $(SRC)

lazy:
	$(CC) -o $(NAME) $(SRC)

abstractVM:
	$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all $(NAME) clean fclean re debug lazy

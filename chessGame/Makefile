# Makefile
#
#
CC= gcc -fsanitize=address
CPPFLAGS=
CFLAGS= -Wall -Wextra
LDFLAGS= -lm
LDLIBS=

SRC = main.c piece.c validMoves.c board.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.o}


all: main
main: $(OBJ)

clean:
	${RM} ${OBJ} ${OBJ_TESTS} ${DEP} ${DEP_TESTS} main && clear

#END

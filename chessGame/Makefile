# Makefile
#
#
CC= gcc -fsanitize=address
CPPFLAGS=
CFLAGS= -Wall -Wextra
LDFLAGS=
LDLIBS=

SRC = main.c piece.c validMoves.c board.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.o}


all: main
main: $(OBJ)

clean:
	${OBJ} ${RM} ${EXE}

#END

# Makefile
#
#
bin = Chess.exe

SRC = main.c piece.c validMoves.c board.c moves.c visual.c AI/movesGen.c AI/chessAI.c 

CC= gcc -fsanitize=address
CPPFLAGS=
CFLAGS= -Wall -Wextra -fsanitize=address
LDFLAGS= -lm
LDLIBS=

OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

#$(bin): $(SRC)
#	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(bin)

all: main
main: $(OBJ)

clean:
	${RM} ${OBJ} ${OBJ_TESTS} ${DEP} ${DEP_TESTS} main && clear

#END

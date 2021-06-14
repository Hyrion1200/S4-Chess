# Makefile
#
#
bin = Chess.exe

SRC = main.c piece.c validMoves.c board.c moves.c visual.c AI/movesGen.c AI/chessAI.c uci.c stats.c

CC= gcc #-fsanitize=address
CPPFLAGS=
FLAGS = -std=gnu99 -Iinclude
#CFLAGS= -#fPIC -Wall -Wextra -O2 -g
CFLAGS = -O2 -g
TARGET_LIB = lib.so
LDFLAGS= -lm #-shared
LDLIBS=

OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

#$(bin): $(SRC)
#	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(bin)

LINK.c := $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

.PHONY: all
#all: $(TARGET_LIB)
#$(TARGET_LIB): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

#$(SRC:.c=.d):%.d:%.c
#	$(CC) $(CFLAGS) -MM $< >$@

#include $(SRC:.c=.d)

all: main

main: $(OBJ)


.PHONY: clean
clean:
	${RM} ${OBJ} ${OBJ_TESTS} ${DEP} ${DEP_TESTS} main && clear

#END

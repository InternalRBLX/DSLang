CC = gcc
CFLAGS = -c -std=c99 -g
LDFLAGS = -g
SRC = ${wildcard src/*.c}
HDR = ${wildcard include/*.h}
OBJ = ${SRC:.c=.o}
EXEC = stample

all: ${SRC} ${OBJ} ${EXEC}

${EXEC}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

%.0: %.c ${HDR}
	${CC} ${CFLAGS} $< -o $@

clean:
	rm src/*.o ${EXEC}
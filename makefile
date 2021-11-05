CC = gcc 
INCLUDES = -Iinclude
CFLAGS = $(INCLUDES)
LIBDIR = lib
SRC = src
LIB = $(LIBDIR)/scl.a
OBJ = obj/list.o


all: ${LIB} ${BIN}

clean: 
	rm -f lib/* obj/* bin/*

${LIB}: ${OBJ}
	ar rcs ${LIB} ${OBJ}

obj/list.o: src/list.c
	${CC} ${CFLAGS} -c $< -o $@
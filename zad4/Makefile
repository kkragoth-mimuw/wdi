CC = gcc
CFLAGS = -Wall -std=c11
TARGET = main

USE_COLOR ?= 1
ifeq ($(USE_COLOR), 1)
	CFLAGS +=-DUSE_COLOR
endif

all: $(TARGET)

node.o: node.c node.h

main.o: main.c node.h

main: main.o node.o

clean:
	rm -f *.o $(TARGET)

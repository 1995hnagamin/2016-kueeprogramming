.PHONY: all clean

CFLAGS += -std=c99 -Wall -Wpedantic
LDLIBS += -lm

EXECUTABLES = 1 2 3
OBJS = matrix.o

all: $(EXECUTABLES)

matrix.o: matrix.h

2: matrix.o

clean:
	rm -f $(EXECUTABLES) $(OBJS)

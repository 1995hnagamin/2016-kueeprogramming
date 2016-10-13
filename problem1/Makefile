.PHONY: all clean

CFLAGS += -std=c99

EXECUTABLES = 1 2
OBJS = matrix.o

all: $(EXECUTABLES)

matrix.o: matrix.h

2: matrix.o

clean:
	rm -f $(EXECUTABLES) $(OBJS)

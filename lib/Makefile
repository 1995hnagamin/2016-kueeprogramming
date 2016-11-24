.PHONY: all clean

TARGETS = matrix.o lu.o
CFLAGS += -std=c99 -Wall -Wpedantic
LDLIBS += -lm

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

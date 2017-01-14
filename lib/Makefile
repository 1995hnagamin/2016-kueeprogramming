.PHONY: all clean

ROOTDIR = ..
INCDIR = -I$(ROOTDIR)/include

TARGETS = matrix.o lu.o mathutil.o
CFLAGS += -std=c99 -Wall -Wpedantic $(INCDIR)
LDLIBS += -lm

all: $(TARGETS)

clean:
	rm -f $(TARGETS)

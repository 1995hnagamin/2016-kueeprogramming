.PHONY: all clean

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib

CFLAGS += -std=c99 -Wall -Wpedantic -I$(LIBDIR)
LDLIBS += -lm

EXECUTABLES = 1 2

all: $(EXECUTABLES)

1: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

2: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

$(LIBDIR)/matrix.o:
	$(MAKE) -C $(LIBDIR) $@

clean:
	rm -f $(EXECUTABLES) $(OBJS)

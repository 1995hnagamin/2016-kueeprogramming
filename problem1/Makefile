.PHONY: all clean

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib

CFLAGS += -std=c99 -Wall -Wpedantic -I$(LIBDIR)
LDLIBS += -lm

EXECUTABLES = 1 2 3

all: $(EXECUTABLES)

2: $(LIBDIR)/matrix.o

$(LIBDIR)/matrix.o:
	$(MAKE) -C $(LIBDIR) $@

clean:
	rm -f $(EXECUTABLES) $(OBJS)

.PHONY: all clean

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib

CFLAGS += -std=c99 -Wall -Wpedantic -I$(LIBDIR)
LDLIBS += -lm

EXECUTABLES = 1 2 3 4
OUTPUTS = $(EXECUTABLES:=.output)

all: $(EXECUTABLES) $(OUTPUTS)

1: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

2: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

3: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

4: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

%.output: %
	./$^ > $@

$(LIBDIR)/matrix.o:
	$(MAKE) -C $(LIBDIR) $@

clean:
	rm -f $(EXECUTABLES) $(OBJS)

.PHONY: all clean

.SUFFIXES: .gnp .png

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib
INCDIR += -I$(ROOTDIR)/include

CFLAGS += -std=c99 -Wall -Wpedantic $(INCDIR)
LDLIBS += -lm

OBJS = jacobi.o
EXECUTABLES = prob1
GNUPLOTSCRIPTS =
OUTPUTS = $(EXECUTABLES:=.dat)
IMAGES = $(GNUPLOTSCRIPTS:%.gnp=%.png)

all: $(EXECUTABLES) $(OUTPUTS) $(IMAGES)

%.dat: %
	./$^ > $@

.gnp.png :
	gnuplot $<

prob1: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

clean:
	rm -f $(EXECUTABLES) $(OBJS) $(OUTPUTS) $(IMAGES)

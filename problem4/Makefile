.PHONY: all clean

.SUFFIXES: .gnp .png

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib
INCDIR += -I$(ROOTDIR)/include

CFLAGS += -std=c99 -Wall -Wpedantic $(INCDIR)
LDLIBS += -lm

OBJS = jacobi.o
EXECUTABLES = prob1_1 prob1_2
GNUPLOTSCRIPTS = 1_1_dissim.gnp
OUTPUTS = $(EXECUTABLES:=.dat)
IMAGES = $(GNUPLOTSCRIPTS:%.gnp=%.png)

all: $(EXECUTABLES) $(OUTPUTS) $(IMAGES)

%.dat: %
	./$^ > $@

.gnp.png :
	gnuplot $<

prob1_1: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

prob1_2: jacobi.o $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

1_1_dissim.png: prob1_1.dat

clean:
	rm -f $(EXECUTABLES) $(OBJS) $(OUTPUTS) $(IMAGES)

.PHONY: all clean

.SUFFIXES: .gnp .png

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib
INCDIR += -I$(ROOTDIR)/include

CFLAGS += -std=c99 -Wall -Wpedantic $(INCDIR)
LDLIBS += -lm

OBJS = jacobi.o util2.o
EXECUTABLES = prob1_1 prob1_2 prob2_1 prob2_2
GNUPLOTSCRIPTS = 1_1_dissim.gnp 2_1_error.gnp 2_2_error.gnp
OUTPUTS = $(EXECUTABLES:=.dat)
IMAGES = $(GNUPLOTSCRIPTS:%.gnp=%.png)

all: $(EXECUTABLES) $(OUTPUTS) $(IMAGES)

%.dat: %
	./$^ > $@

.gnp.png :
	gnuplot $<

prob1_1: $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

prob1_2: jacobi.o $(LIBDIR)/matrix.o $(LIBDIR)/lu.o

prob2_1: $(LIBDIR)/mathutil.o util2.o

prob2_2: $(LIBDIR)/mathutil.o util2.o

1_1_dissim.png: prob1_1.dat

2_1_error.png: prob2_1.dat

2_2_error.png: prob2_2.dat

clean:
	rm -f $(EXECUTABLES) $(OBJS) $(OUTPUTS) $(IMAGES)

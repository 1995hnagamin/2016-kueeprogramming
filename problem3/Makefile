.PHONY: all clean

.SUFFIXES: .gnp .png

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib
INCDIR += -I$(ROOTDIR)/include

CFLAGS += -std=c99 -Wall -Wpedantic $(INCDIR)
LDLIBS += -lm

OBJS = util.o euler.o heun.o runge_kutta.o
EXECUTABLES = prob1 prob2 prob3_1 prob3_2 prob4_1 prob4_2
GNUPLOTSCRIPTS = \
	1_r.gnp 1_error.gnp \
	2_error.gnp \
	3_r.gnp 3_error.gnp \
	4_r.gnp 4_error.gnp
OUTPUTS = $(EXECUTABLES:=.dat)
IMAGES = $(GNUPLOTSCRIPTS:%.gnp=%.png)

all: $(EXECUTABLES) $(OUTPUTS) $(IMAGES)

%.dat: %
	./$^ > $@

.gnp.png :
	gnuplot $<

1_r.png : prob1.dat

1_error.png : prob1.dat

2_error.png : prob2.dat

3_r.png : prob3_1.dat

3_error.png : prob3_2.dat

4_r.png : prob4_1.dat

4_error.png : prob4_2.dat

prob1 : util.o euler.o

prob2 : util.o euler.o

prob3_1 : util.o heun.o

prob3_2 : util.o heun.o

prob4_1 : util.o runge_kutta.o

prob4_2 : util.o runge_kutta.o

clean:
	rm -f $(EXECUTABLES) $(OBJS) $(OUTPUTS) $(IMAGES)

.PHONY: all clean

.SUFFIXES: .gnp .png

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib

CFLAGS += -std=c99 -Wall -Wpedantic -I$(LIBDIR)
LDLIBS += -lm

OBJS = util.o
EXECUTABLES = prob1 prob2 prob3_1 prob4_1
GNUPLOTSCRIPTS = \
	1_r.gnp 1_error.gnp \
	2_error.gnp \
	3_r.gnp 3_error.gnp
OUTPUTS = $(EXECUTABLES:=.dat)
IMAGES = $(GNUPLOTSCRIPTS:%.gnp=%.png)

all: $(EXECUTABLES) $(OUTPUTS) $(IMAGES)

%.dat: %
	./$^ > $@

.gnp.png :
	gnuplot $<

1_r.png : prob1.dat

1_error.png : prob1.dat

3_r.png : prob3_1.dat

3_error.png : prob3_2.dat

prob1 : util.o

prob2 : util.o

prob3_1 : util.o

clean:
	rm -f $(EXECUTABLES) $(OBJS) $(OUTPUTS) $(IMAGES)

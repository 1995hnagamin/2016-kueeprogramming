.PHONY: all clean

.SUFFIXES: .gnp .png

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib

CFLAGS += -std=c99 -Wall -Wpedantic -I$(LIBDIR)
LDLIBS += -lm

EXECUTABLES = prob1 prob2 prob3 prob4_r
GNUPLOTSCRIPTS = 1_r.gnp 1_error.gnp 2_error.gnp 3_r.gnp
OUTPUTS = $(EXECUTABLES:=.dat)
IMAGES = $(GNUPLOTSCRIPTS:%.gnp=%.png)

all: $(EXECUTABLES) $(OUTPUTS) $(IMAGES)

%.dat: %
	./$^ > $@

.gnp.png :
	gnuplot $<

1_r.png : prob1.dat

1_error.png : prob1.dat

clean:
	rm -f $(EXECUTABLES) $(OBJS) $(OUTPUTS) $(IMAGES)

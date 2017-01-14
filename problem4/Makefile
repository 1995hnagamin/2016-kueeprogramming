.PHONY: all clean

.SUFFIXES: .gnp .png

ROOTDIR = ..
LIBDIR = $(ROOTDIR)/lib

CFLAGS += -std=c99 -Wall -Wpedantic -I$(LIBDIR)
LDLIBS += -lm

OBJS = jacobi.o
EXECUTABLES =
GNUPLOTSCRIPTS =
OUTPUTS = $(EXECUTABLES:=.dat)
IMAGES = $(GNUPLOTSCRIPTS:%.gnp=%.png)

all: $(EXECUTABLES) $(OUTPUTS) $(IMAGES)

%.dat: %
	./$^ > $@

.gnp.png :
	gnuplot $<

clean:
	rm -f $(EXECUTABLES) $(OBJS) $(OUTPUTS) $(IMAGES)

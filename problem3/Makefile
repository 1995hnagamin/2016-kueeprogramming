.PHONY: all clean distclean

ROOTDIR = ..

EXECUTABLES = prob1.out
GNUPLOTSCRIPTS = 1_r.gnp 1_error.gnp
OUTPUTS = $(EXECUTABLES:%.out=%.dat)
IMAGES = $(GNUPLOTSCRIPTS:%.gnp=%.png)

all: $(EXECUTABLES) $(OUTPUTS) $(IMAGES)

%.cmo : %.ml
	ocamlc -c $^

prob1.out : util.cmo prob1.cmo
	ocamlc -o $@ $^

%.dat: %.out
	./$^ > $@

%.png : %.gnp
	gnuplot $^

clean:
	rm -f $(EXECUTABLES)

distclean:
	rm -f $(EXECUTABLES) *.cmo *.png *.cmi

CFLAGS = -Wall -g
files = ex1.c
GCC = gcc
all: targets ex3

targets: ex1.c
	$(GCC) $(CFLAGS) $(files) -o ex1
ex3: ex3.c
	$(GCC) $(CFLAGS) ex3.c -o ex3

ex19:ex19.c dbg.h
	$(GCC) $(CFLAGS) -I . ex19.c -o ex19

clean:
	rm -f ex7
	rm -f ex3
	rm -f ex8
	rm -f ex9
	rm -f ex10
	rm -f ex11
	rm -f ex12
	rm -f ex13
	rm -f ex14
	rm -f ex15
	rm -f ex16
	rm -f ex17
	rm -f ex19
	rm -rf *.dSYM


############################# Makefile ##########################

LIBS := -lm
COMPILER := gcc
GEN_LIB := ar rv

# static lib 
staticlib: 
	$(COMPILER) -c rsa.c -o rsa.o
	$(GEN_LIB) rsa.a rsa.o
	rm -rf rsa.o

# Compiled source
compsrc: 
	$(COMPILER) rsa.c rsa_ex.c -o rsa.exec $(LIBS)

# Clear repo
clear:
	rm -rf rsa_ex.o
	rm -rf rsa_ex.a
	rm -rf rsa.o
	rm -rf rsa.exec
	rm -rf rsa.a
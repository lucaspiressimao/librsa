############################# Makefile ##########################

LIBS := -lm
COMPILER := gcc
GEN_LIB := ar rv
DELETE := rm -rf

# static lib 
staticlib: 
	$(COMPILER) -c src/rsa.c -o rsa.o $(LIBS)
	$(GEN_LIB) rsa.a rsa.o
	$(DELETE) rsa.o

# Compiled source
compsrc: 
	$(COMPILER) src/rsa.c rsa_ex.c -o rsa.exec $(LIBS)

# Clear repo
clear:
	$(DELETE) rsa_ex.o
	$(DELETE) rsa_ex.a
	$(DELETE) rsa.o
	$(DELETE) rsa.exec
	$(DELETE) rsa.a
############################# Makefile ##########################

LIBS := -lm
COMPILER := gcc
GEN_LIB := ar rv
DELETE := rm -rf
FILE_LIST := src/rsa.c

# static lib 
staticlib: 
	$(COMPILER) -c $(FILE_LIST) -o out/rsa.o $(LIBS)
	$(GEN_LIB) out/rsa.a out/rsa.o
	$(DELETE) out/rsa.o

# Compiled source
compsrc: 
	$(COMPILER) $(FILE_LIST) rsa_ex.c -o out/rsa.exec $(LIBS)

# Clear repo
clear:
	$(DELETE) out/rsa_ex.o
	$(DELETE) out/rsa_ex.a
	$(DELETE) out/rsa.o
	$(DELETE) out/rsa.exec
	$(DELETE) out/rsa.a
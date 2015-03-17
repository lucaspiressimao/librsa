############################# Makefile ##########################
# static lib 
staticlib: 
	gcc -c rsa_ex.c -o rsa_ex.o
	ar rv rsa_ex.a rsa_ex.o
	rm -rf rsa_ex.o

# Compiled source
compsrc:
	gcc rsa_ex.c -o rsa -lm

# Clear repo
clear:
	rm -rf rsa_ex.o
	rm -rf rsa_ex.a
	rm -rf rsa	
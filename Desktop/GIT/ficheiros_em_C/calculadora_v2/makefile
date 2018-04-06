#Simple example of makefile
objects = calculadora2.o
calculadora2: $(objects)
	gcc -o calculadora2 $(objects) -lm
calculadora2.o: calculadora2.c calculadora2.h
	gcc -c calculadora2.c
clean:
	rm calculadora2 $(objects)

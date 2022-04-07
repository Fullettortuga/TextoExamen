texto : texto.o tigr.o
	gcc -o texto texto.o tigr.o
texto.o: texto.cpp
	gcc -c texto.cpp
tigr.o: tigr.c tigr.h
	gcc -c tigr.c
clean:
	del texto texto.o tigr.o


CFLAGS = -I../..
ifeq ($(OS),Windows_NT)
        LDFLAGS = -s -lopengl32 -lgdi32
else
        UNAME_S := $(shell uname -s)
        ifeq ($(UNAME_S),Darwin)
                LDFLAGS = -framework OpenGL -framework Cocoa
        else ifeq ($(UNAME_S),Linux)
                LDFLAGS = -s -lGLU -lGL -lX11
        endif
endif

texto: texto.o tigr.o
	g++ -o texto texto.o tigr.o $(CFLAGS) $(LDFLAGS)
texto.o: texto.cpp
	g++ -c texto.cpp
tigr.o: tigr.c tigr.h
	g++ -c tigr.c
clean:
	del texto texto.o tigr.o



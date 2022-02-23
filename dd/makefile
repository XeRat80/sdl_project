game: main.o texte.o son.o image.o
	gcc main.o image.o texte.o son.o -lSDL -lSDL_image -lSDL_ttf  -lSDL_mixer -o game 
main.o:main.c
	gcc -c main.c -g 
texte.o:texte.c
	gcc -c texte.c -g 
son.o:son.c
	gcc -c son.c -g
image.o:image.c
	gcc -c image.c -g

clean: 
	rm -rf *.o

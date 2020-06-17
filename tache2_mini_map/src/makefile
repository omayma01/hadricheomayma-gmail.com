prog: main.o   ennemi.o jeu.o background.o hero.o 
	gcc  main.o   ennemi.o jeu.o background.o hero.o    -o prog -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer  -g
main.o:main.c
	gcc -c main.c  -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
jeu.o:jeu.c
	gcc -c jeu.c -g
ennemi.o:ennemi.c
	gcc -c ennemi.c -g
hero.o:hero.c
	gcc -c hero.c -g
background.o:background.c
	gcc -c background.c -g

clean:
	rm -fr *.o
mrproper:clean
	rm -f prog

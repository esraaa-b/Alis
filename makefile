prog:main.o Backg.o Buttons.o intro.o perso.o  gestionvie.o background.o enigma.o entite_secondaire.o minimap.o jeu.o
	gcc main.o Backg.o Buttons.o  intro.o perso.o gestionvie.o background.o enigma.o entite_secondaire.o minimap.o jeu.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer -lm
main.o:main.c
	gcc -c main.c -g
Backg.o:Backg.c
	gcc -c Backg.c -g
Buttons.o:Buttons.c
	gcc -c Buttons.c -g

intro.o:intro.c
	gcc -c intro.c -g

perso.o : perso.c
	gcc -c perso.c -g

gestionvie.o : gestionvie.c
	gcc -c gestionvie.c -g

background.o : background.c
	gcc -c background.c -g

enigma.o : enigma.c
	gcc -c enigma.c -g

entite_secondaire.o : entite_secondaire.c
	gcc -c entite_secondaire.c -g

minimap.o : minimap.c
	gcc -c minimap.c -g


jeu.o : jeu.c
	gcc -c jeu.c -g


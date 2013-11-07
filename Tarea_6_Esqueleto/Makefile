all:  Condiciones.dat  plot 

plot: ./evolve.x Condiciones_iniciales.dat
	python plot.py
Condiciones.dat:IC.x
	./IC.x 23 32 445 566
IC.x:IC.c
	cc IC.c -o IC.x -lm
evolve.x : evolve.c
	cc evolve.c -o evolve.x -lm 

IC.X: IC.c
	cc IC.c -o IC.X -lm

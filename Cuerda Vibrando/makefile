all: string_0.001000.pdf 

string_0.001000.pdf: plot.py string_0.001000.dat
	python plot.py string_0.001000.dat

string_0.001000.dat: string.x
	./string.x 0.001

string.x : Cuerda_Vibrando.c
	cc Cuerda_Vibrando.c -lm -o ./string.x 
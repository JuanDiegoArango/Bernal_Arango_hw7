all: sod_test.x estado_0.010000.dat estado_0.010000.pdf

estado_0.010000.pdf:estado_0.010000.dat sod_plot.py
	python sod_plot.py estado_0.010000.dat

estado_0.010000.dat:sod_test.x
	./sod_test.x 0.01

sod_test.x:shock.c
	cc shock.c -lm -o sod_test.x

clean:
	rm *.dat *.pdf
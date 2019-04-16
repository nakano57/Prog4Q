main: write.o read.o negaposi.o rotation.o check.o cut.o black.o main.c
	gcc -Wall write.o read.o negaposi.o rotation.o check.o cut.o black.o main.c -o main

negaposi.o:
	gcc -c negaposi.c

write.o:
	gcc -c write.c

check.o:
	gcc -c check.c

rotation.o:
	gcc -c rotation.c

read.o:
	gcc -c read.c

cut.o:
	gcc -c cut.c

black.o:
	gcc -c black.c

clean:
	rm -rf *.o main fruit_negaposi.pgm fruit_rotation.pgm fruit_cut.pgm fruit_fill.pgm lena_negaposi.pgm lena_rotation.pgm lena_cut.pgm lena_fill.pgm a.out a.out.dSYM

test: main
	./main negaposi fruit_460_460.pgm fruit_negaposi.pgm
	cmp fruit_negaposi.pgm fruit_negaposi_example.pgm
	./main rotation fruit_460_460.pgm fruit_rotation.pgm
	cmp fruit_rotation.pgm fruit_rotation_example.pgm
	./main cut fruit_460_460.pgm fruit_cut.pgm 100 100 200 200
	cmp fruit_cut.pgm fruit_cut_example.pgm
	./main fill fruit_460_460.pgm fruit_fill.pgm 100 100 200 200
	cmp fruit_fill.pgm fruit_fill_example.pgm
	./main negaposi lena.pgm lena_negaposi.pgm
	cmp lena_negaposi.pgm lena_negaposi_example.pgm
	./main rotation lena.pgm lena_rotation.pgm
	cmp lena_rotation.pgm lena_rotation_example.pgm
	./main cut lena.pgm lena_cut.pgm 100 100 200 200
	cmp lena_cut.pgm lena_cut_example.pgm
	./main fill lena.pgm lena_fill.pgm 100 100 200 200
	cmp lena_fill.pgm lena_fill_example.pgm


rebuild:
	gcc -c negaposi.c
	gcc -c write.c
	gcc -c check.c
	gcc -c rotation.c
	gcc -c read.c
	gcc -c cut.c
	gcc -c black.c

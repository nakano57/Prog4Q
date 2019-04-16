clipimage: clipimage.c
	gcc -Wall -o clipimage clipimage.c

clipimage_advanced: clipimage_advanced.c
	gcc -Wall -o clipimage_advanced clipimage_advanced.c

clean:
	rm -rf clipimage clipimage_advanced fruit_clipped.pgm lena_clipped.pgm 0 0.dSYM

test: clipimage
	./clipimage fruit_460_460.pgm 100 100 150 150 fruit_clipped.pgm
	cmp fruit_clipped.pgm fruit_clipped_example.pgm

test2: clipimage_advanced
	./clipimage_advanced lena.pgm 200 200 150 150 lena_clipped.pgm
	cmp lena_clipped.pgm lena_clipped_example.pgm

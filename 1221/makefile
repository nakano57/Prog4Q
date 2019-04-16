clipimage: clipimage.c
	gcc -Wall -o clipimage clipimage.c

clipimage_advanced: clipimage_advanced.c
	gcc -Wall -o clipimage_advanced clipimage_advanced.c

clean:
	rm -f clipimage clipimage_advanced fruit_clipped.pgm lena_clipped.pgm

test: clipimage
	./clipimage
	cmp fruit_clipped.pgm fruit_clipped_example.pgm

test2: clipimage_advanced
	./clipimage_advanced fruit_460_460.pgm fruit_clipped.pgm
	cmp fruit_clipped.pgm fruit_clipped_example.pgm
	./clipimage_advanced lena.pgm lena_clipped.pgm
	cmp lena_clipped.pgm lena_clipped_example.pgm

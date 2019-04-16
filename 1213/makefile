reverse: reverse.c
	gcc -Wall -o reverse reverse.c

reverseall: reverseall.c
	gcc -Wall -o reverseall reverseall.c

clean:
	rm -rf reverse reverseall alice_reverse.txt alice_reverseall.txt a.out a.out.dSYM

test: reverse
	./reverse
	diff -q alice_reverse_example.txt alice_reverse.txt

test2: reverseall
	./reverseall
	diff -q alice_reverseall_example.txt alice_reverseall.txt

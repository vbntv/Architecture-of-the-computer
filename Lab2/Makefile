binary: main.o libworld.a
	gcc -o binary main.o -L. -lworld

main.o: main.c
	gcc -c main.c

libworld.a: library.o
	ar cr libworld.a library.o

library.o: library.c
	gcc -c h_world.c

clean:
	rm -f *.o *.a binary


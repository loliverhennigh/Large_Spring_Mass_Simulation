all: test

spring.o: spring.c
	gcc $(CFLAGS) -c backer.o 

particle.o: particle.c
	gcc $(CFLAGS) -c backer.c

clean:
	rm -f *.o backer

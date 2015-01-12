all: test

test: test.o spring.o particle.o lsms.o
	gcc test.o spring.o particle.o lsms.o -o test -lm

test.o: test.c
	gcc $(CFLAGS) -c test.c 

spring.o: spring.c
	gcc $(CFLAGS) -c spring.c 

particle.o: particle.c
	gcc $(CFLAGS) -c particle.c 

lsms.o: lsms.c
	gcc $(CFLAGS) -c lsms.c

clean:
	rm -f *.o test
